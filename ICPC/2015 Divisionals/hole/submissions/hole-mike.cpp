//
//  minigolf.cpp
//
//  AC intended, but having blundered in reading the problem, it seems
//  likely that I'll have blundered in coding too
//
//  Intent is to first test direct path against walls, then
//  for each possible reflection case:
//  1. Check can reflect i.e. ball and hole on same side of wall
//     and wall intersects ball to reflected hole segment
//  2. For ball to reflected hole segment and hole to reflected ball
//     segment check whether a wall (other than reflecting one)
//     touches or intersects it at or before the reflection point
//
//  Solution is heavy on use of stuff that I should have prepared and tested
//  beforehand

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// code for rational not routinely reducing by gcd
struct rat
{
    ll num;
    ll den;
    
    rat(): num(0), den(1){}
    rat(ll n): num(n), den(1){}
    rat(ll n, ll d): num(n), den(d){}
};

rat operator+(rat a, rat b)
{
    return rat(a.num * b.den + b.num * a.den, a.den * b.den);
}

rat operator-(rat a, rat b)
{
    return rat(a.num * b.den - b.num * a.den, a.den * b.den);
}

rat operator*(rat a, rat b)
{
    return rat(a.num * b.num, a.den * b.den);
}

rat operator/(rat a, rat b)
{
    return (b.num > 0) ?
    rat(a.num * b.den, a.den * b.num) :
    rat(-a.num * b.den, -a.den * b.num);
}

bool operator<(rat a, rat b)
{
    return a.num * b.den < b.num * a.den;
}

bool operator<=(rat a, rat b)
{
    return a.num * b.den <= b.num * a.den;
}

bool operator>(rat a, rat b)
{
    return a.num * b.den > b.num * a.den;
}

bool operator>=(rat a, rat b)
{
    return a.num * b.den >= b.num * a.den;
}

bool operator==(rat a, rat b)
{
    return a.num * b.den == b.num * a.den;
}

bool operator!=(rat a, rat b)
{
    return a.num * b.den != b.num * a.den;
}

// gcd reduction of rational for use where it seems worthwhile
rat simplify(rat r)
{
    ll m = (r.num >= 0) ? r.num : -r.num;
    ll n = r.den;
    
    while(n != 0)
    {
        ll t = m % n;
        m = n;
        n = t;
    }
    
    return rat(r.num/m, r.den/m);
}

// two component vector
struct vec
{
    rat x;
    rat y;
    
    vec() : x(0), y(0){}
    vec(rat xx, rat yy): x(xx), y(yy){}
};

vec operator+(vec a, vec b)
{
    return vec(a.x + b.x, a.y + b.y);
}

vec operator-(vec a, vec b)
{
    return vec(a.x - b.x, a.y - b.y);
}

rat dot(vec a, vec b)
{
    return a.x * b.x + a.y * b.y;
}

rat l2(vec a)
{
    return dot(a, a);
}

// line segment from p1 to p2
struct seg
{
    vec p1;
    vec p2;
    
    seg() : p1(vec()), p2(vec()){}
    seg(vec a, vec b) : p1(a), p2(b){}
};

// direction to p from s: +1 left / -1 right / 0 in line
int dir(seg s, vec p)
{
    vec d1 = s.p2 - s.p1;
    vec d2 = p - s.p1;
    rat disc = d1.x * d2.y - d2.x * d1.y;
    if(disc.num > 0) return 1;
    if(disc.num < 0) return -1;
    return 0;
}

// return 0 to 1 distance of p along path, or 2 if not touching
rat touch(seg path, vec p)
{
    rat where = rat(2);
    if(dir(path, p) == 0)
    {
        if(path.p1.x != path.p2.x)
        {
            where = (p.x - path.p1.x)/(path.p2.x - path.p1.x);
        }
        else
        {
            where = (p.y - path.p1.y)/(path.p2.y - path.p1.y);
        }
    }
    if( (where < rat()) || (where > rat(1)) ) return rat(2);
    return where;
}

// return lesser 0 to 1 distance of wall point along path, or 2 if not touching
rat touch(seg path, seg wall)
{
    rat touch1 = touch(path, wall.p1);
    rat touch2 = touch(path, wall.p2);
    
    if(touch1 < touch2) return touch1;
    return touch2;
}

// return 0 to 1 distance of intersection along path, or 2 if not crossing
rat intersect(seg path, seg wall)
{
    if( (dir(path, wall.p1) * dir(path, wall.p2) == -1) &&
       (dir(wall, path.p1) * dir(wall, path.p2) == -1) )
    {
        rat a = path.p2.x - path.p1.x;
        rat b = wall.p1.x - wall.p2.x;
        rat c = path.p2.y - path.p1.y;
        rat d = wall.p1.y - wall.p2.y;
        rat e = wall.p1.x - path.p1.x;
        rat f = wall.p1.y - path.p1.y;
        
        return simplify((d * e - b * f)/simplify(a * d - b * c));
    }
    return rat(2);
}

//  return reflection of p about line of wall
vec reflect(vec p, seg wall)
{
    vec diffp = p - wall.p1;
    vec diff2 = wall.p2 - wall.p1;
    rat multiplier = simplify((rat(2)*dot(diffp, diff2))/l2(diff2));
    return wall.p1 - diffp + vec(multiplier*diff2.x, multiplier*diff2.y);
}

//  Check for wall touching or intersecting path before or at reflection
//  distance (in 0 to 1) sense. (Ignore reflecting wall in this.)
bool valid_path(seg path, rat distance, vector<seg> &walls, int reflector)
{
    for(int i = 0; i < (int)walls.size(); i++)
    {
        if(i == reflector) continue;
        if(touch(path, walls[i]) <= distance)
        {
            return false;
        }
        if(intersect(path, walls[i]) <= distance)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    ll W, H;
    vec ball, hole;
    vector<seg> walls;
    
    // read input and set up walls
    cin >> N >> W >> H;
    walls.push_back(seg(vec(0,0), vec(W,0)));
    walls.push_back(seg(vec(W,0), vec(W,H)));
    walls.push_back(seg(vec(W,H), vec(0,H)));
    walls.push_back(seg(vec(0,H), vec(0,0)));
    ll x, y;
    cin >> x >> y;
    ball = vec(x, y);
    cin >> x >> y;
    hole = vec(x, y);
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        vec p1(x, y);
        cin >> x >> y;
        vec p2(x, y);
        walls.push_back(seg(p1,p2));
    }
    
    if(valid_path(seg(ball, hole), rat(1), walls, -1))
    {
        cout << "YES\n";
        return 0;
    }
    
    for(int i = 0; i < (int)walls.size(); i++)
    {
        seg wall = walls[i];
        if((dir(wall, ball) * dir(wall, hole)) == 1)
        {
            vec reflected_hole = reflect(hole, wall);
            seg path_to_hole = seg(ball, reflected_hole);
            if(touch(path_to_hole, wall) != rat(2))
            {
                continue;
            }
            rat hits_wall_at = intersect(path_to_hole, wall);
            if(hits_wall_at == rat(2))
            {
                continue;
            }
            if(!valid_path(path_to_hole, hits_wall_at, walls, i))
            {
                continue;
            }
            vec reflected_ball = reflect(ball, wall);
            seg path_to_ball = seg(hole, reflected_ball);
            hits_wall_at = intersect(path_to_ball, wall);
            if(valid_path(path_to_ball, hits_wall_at, walls, i))
            {
                cout << "YES\n";
                return 0;
            }
            
        }
    }
    
    cout << "NO\n";
    return 0;
}

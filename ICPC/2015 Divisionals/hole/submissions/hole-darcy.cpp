#include <bits/stdc++.h>
using namespace std;
using namespace std::rel_ops;

struct Point { long long x,y; };
struct Line  { Point p,q; };

Point operator-(Point p,Point q){ return {p.x-q.x,p.y-q.y}; }
Point operator+(Point p,Point q){ return {p.x+q.x,p.y+q.y}; }
Point operator*(long long f,Point p){ return {p.x*f,p.y*f}; }

long long cross(Point p,Point q){ return p.x*q.y - q.x*p.y; }

// Where is r in comparison to L?
int orientation(const Line& L,const Point& r){
	long long c = cross(L.p-L.q,r-L.q);
	if(c == 0) return 0;
	return (c < 0 ? -1 : 1);
}

// Checks if p is on L (assumes p is collinear with L)
bool on_segment(const Line& L, const Point& p){
	Point p1 = L.p, p2 = L.q, p3 = p;
	return ((p1.x <= p3.x && p3.x <= p2.x) || (p2.x <= p3.x && p3.x <= p1.x)) &&
	((p1.y <= p3.y && p3.y <= p2.y) || (p2.y <= p3.y && p3.y <= p1.y));
}

// Determines if 2 line segments intersect
//  - 0 == no intersections
//  - 1 == interior intersection
//  - 2 == intersection at endpoint of L1
//  - 3 == intersection at endpoint of L2 (and not endpoint of L1)
int intersect(const Line& L1,const Line& L2){
	int d1 = orientation(L2,L1.p), d2 = orientation(L2,L1.q);
	int d3 = orientation(L1,L2.p), d4 = orientation(L1,L2.q);

	if(d1 == 0 && on_segment(L2,L1.p)) return 2;
	if(d2 == 0 && on_segment(L2,L1.q)) return 2;
	if(d3 == 0 && on_segment(L1,L2.p)) return 3;
	if(d4 == 0 && on_segment(L1,L2.q)) return 3;
	
	if(d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0) return 0;

	return (d1 == -d2 && d3 == -d4); // Either 0 or 1
}

bool lt(long long n1,long long d1,long long n2,long long d2){
	long long whole1 = n1 / d1, whole2 = n2 / d2;
	if(whole1 != whole2) return whole1 < whole2;

	n1 %= d1; n2 %= d2;
	if(n2 == 0) return false;
	if(n1 == 0) return true;

	return lt(d2,n2,d1,n1);
}

// - Returns true if L1 intersects L strictly before L2.
// - (L and L1) are not collinear, but the other pairs may be.
// - We know that L intersects both L1 and L2.
bool intersects_first(const Line& L,const Line& L1,const Line& L2){
	long long num1 = cross(L1.q-L1.p,L.p-L1.p), num2 = cross(L2.q-L2.p,L.p-L2.p);
	long long den1 = cross(L.q-L.p,L1.q-L1.p),  den2 = cross(L.q-L.p,L2.q-L2.p);

	assert(den1 != 0); // Since they are not collinear
	if(den2 != 0) // If L and L2 are not collinear
		return lt(num1,den1,num2,den2);

	// Check the endpoints of L2
	for(Point end : {L2.p,L2.q}){
		if(L.p.x != L.q.x){
			num2 = end.x - L.p.x;
			den2 = L.q.x - L.p.x;
		} else {
			num2 = end.y - L.p.y;
			den2 = L.q.y - L.p.y;
		}

		if(lt(num1,den1,num2,den2)) return true;
	}
	return false;
}

// The reflected point is ans.first/ans.second
pair<Point,long long> reflect(const Point& p,const Line& L){
	long long b = L.p.x - L.q.x, a = L.q.y - L.p.y, c = cross(L.q,L.p);
	long long nx = b * (b*p.x - a*p.y) - a*c;
	long long ny = a * (a*p.y - b*p.x) - b*c;
	long long d = a*a + b*b;
	return make_pair(Point({2*nx - d*p.x,2*ny - d*p.y}),d);
}

int main(){
	int n; cin >> n;
	int W,H; cin >> W >> H;

	Point ball, hole;
	cin >> ball.x >> ball.y >> hole.x >> hole.y;

	vector<Line> A(n+4);
	for(int i=0;i<n;i++)
		cin >> A[i].p.x >> A[i].p.y >> A[i].q.x >> A[i].q.y;
	
	A[n++] = { {0,0}, {W,0} };
	A[n++] = { {0,0}, {0,H} };
	A[n++] = { {W,H}, {W,0} };
	A[n++] = { {W,H}, {0,H} };
	
	bool ans = false;

	// Shoot straight into the hole
	bool straight_in = true;
	for(int i=0;i<(int)A.size();i++)
		if(intersect({ball,hole},A[i]))
			straight_in = false;

	if(straight_in) {
		ans = true;
		cerr << "Shoot straight in" << endl;
	}

	for(int i=0;i<(int)A.size();i++){
		int where_hole = orientation(A[i],hole);
		int where_ball = orientation(A[i],ball);
		if(where_hole == 0 || where_ball == 0) continue;
  	if(where_hole != where_ball) continue; // No bounce since opposite side

	  int ctr = 0; // If this becomes 2, then nothing is in the way!
	  Point mirror;
	  long long mult;
	  vector<Point> ball_and_hole = {ball,hole};
	  for(int dd=0;dd<2;dd++){
	  	Point p = ball_and_hole[dd], q = ball_and_hole[1-dd];
	  	tie(mirror,mult) = reflect(p,A[i]);
	  	for(Line& L : A){
	  		L.p.x *= mult, L.p.y *= mult;
	  		L.q.x *= mult, L.q.y *= mult;
	  	}
	  	p.x *= mult, p.y *= mult;
	  	q.x *= mult, q.y *= mult;
	  	Line shot = {q,mirror};
	  	
	  	if(intersect(A[i],shot) % 2) { // Make sure we bounce
	  		bool in_the_way = false;
	  		for(int j=0;j<(int)A.size();j++)
	  			if(i != j && intersect(shot,A[j]) && !intersects_first(shot,A[i],A[j]))
	  				in_the_way = true;
	  			if(!in_the_way) ctr++;
	  		}
	  		for(Line& L : A){
	  			L.p.x /= mult, L.p.y /= mult;
	  			L.q.x /= mult, L.q.y /= mult;
	  		}
	  		p.x /= mult, p.y /= mult;
	  		q.x /= mult, q.y /= mult;
	  	}
	  	if(ctr == 2){
	  		ans = true;
	  		cerr << "Shoot towards (";
	  		long long gx = __gcd(mirror.x,mult), gy = __gcd(mirror.y,mult);
	  		cerr << mirror.x/gx << "/" << mult/gx << "," << mirror.y/gy << "/" << mult/gy << ").";
	  		cerr << " It will bounce off of ";
	  		cerr << "(" << A[i].p.x << "," << A[i].p.y << ")--(" << A[i].q.x << "," << A[i].q.y << ")." << endl;
	  	}
	  }

	  cout << (ans ? "YES" : "NO") << endl;

	  return 0;
	}

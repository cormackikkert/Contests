from fractions import Fraction
import sys

class Point:
	def __init__(self,x=0,y=0):
		self.x, self.y = Fraction(x), Fraction(y)

	def __str__(self):
		return "({0}, {1})".format(self.x, self.y)

	def __repr__(self):
		return "({0}, {1})".format(self.x, self.y)

	def __eq__(self, other):
		return self.x == other.x and self.y == other.y

	def __lt__(self, other):
		return (self.y == other.y and self.x < other.x) or self.y < other.y

	def __add__(self,other):
		return Point(self.x+other.x,self.y+other.y)

	def __sub__(self,other):
		return Point(self.x-other.x,self.y-other.y)

	def __rmul__(self,other):
		return Point(other*self.x , other*self.y)

def cross(p,q):
	return p.x*q.y - p.y*q.x

class Line:
	def __init__(self,p,q):
		self.p, self.q = p, q

	def __eq__(self,other):
		return self.p == other.p and self.q == other.q

	def __repr__(self):
		return "{0}--{1}".format(self.p, self.q)

	def __str__(self):
		return "{0}--{1}".format(self.p, self.q)

def intersection_point(L1,L2):
	a, b, c, d = L1.p, L1.q, L2.p, L2.q
	num1, num2, den = cross(d-c,a-c), cross(b-a,a-c), cross(b-a,d-c)

	if den != Fraction(0):
		r,s = num1 / den, num2 / den
		if r < Fraction(0) or r > Fraction(1): return (0, None)
		if s < Fraction(0) or s > Fraction(1): return (0, None)
		return 1, a + r*(b-a)

	if num1 != Fraction(0): return (0, None)

	if b < a: a,b = b,a
	if d < c: c,d = d,c

	if a.x == b.x:
		if b.y == c.y: return (1, b)
		if a.y == d.y: return (1, a)
		return (0, None) if (b.y < c.y or d.y < a.y) else (-1, None)
	if b.x == c.x: return (1, b)
	if a.x == d.x: return (1, a)
	return (0, None) if (b.x < c.x or d.x < a.x) else (-1, None)


def orientation(L,r):
	c = cross(L.p - L.q, r - L.q)
	return 0 if c == 0 else (1 if c > 0 else -1)

def reflect(p,L):
	a, b, c = L.q.y - L.p.y, L.p.x - L.q.x, cross(L.q,L.p)
	nx, ny = b * (b*p.x - a*p.y) - a*c, a * (a*p.y - b*p.x) - b*c
	d = Fraction(a*a + b*b)
	on_line = Point(Fraction(nx)/d,Fraction(ny)/d)
	ans = Fraction(2) * on_line - p
	
	return ans

def dist2_to_line(L,p):
    a, b, c = L.q.y - L.p.y, L.p.x - L.q.x, cross(L.q,L.p)
    n, d2 = (a*p.x + b*p.y + c), a*a + b*b
    return Fraction(n*n,d2)
    

def check(lines, shot, ignore_line):
	for line in lines:
		if not (line == ignore_line):
			if intersection_point(line, shot)[0] != 0:
				return False
	return True

def do_case():
    n, W, H = [int(x) for x in input().split()]
    
    bx, by = input().split()
    hx, hy = input().split()

    ball, hole = Point(bx,by), Point(hx,hy)

    L = [
        Line( Point(0,0) , Point(W,0) ),
        Line( Point(0,0) , Point(0,H) ),
        Line( Point(W,H) , Point(W,0) ),
        Line( Point(W,H) , Point(0,H) )
    ]

    for i in range(n):
	    px, py, qx, qy = input().split()
	    L.append( Line( Point(px,py) , Point(qx,qy) ) )

    if check(L, Line(ball,hole), Line( Point(-1,-1), Point(-1,-1) ) ):
	    sys.stderr.write("Shoot straight in\n")
	    return True

    for line in L:
	    where_hole, where_ball = orientation(line,hole), orientation(line,ball)
	    if where_hole == 0: continue
	    if where_hole != where_ball: continue
	    mirror = reflect(hole,line)
	    shot = Line(ball,mirror)
	    k, bounce_point = intersection_point(line,shot)
	    if k != 1: continue
	    if bounce_point == line.p or bounce_point == line.q: continue
	    if not check(L, Line(ball,bounce_point), line): continue
	    if not check(L, Line(bounce_point,hole), line): continue
    	
	    sys.stderr.write("Bounce ball off of " + str(bounce_point) + " on " + str(line) + ".\n")
	    minimumDistance = Fraction(200000000)
	    for otherLine in L:
	        if otherLine != line:
	            minimumDistance = min( minimumDistance, dist2_to_line( otherLine, bounce_point ) )
	            minimumDistance = min( minimumDistance, dist2_to_line( Line(ball,bounce_point), otherLine.p ) )
	            minimumDistance = min( minimumDistance, dist2_to_line( Line(ball,bounce_point), otherLine.q ) )
	            minimumDistance = min( minimumDistance, dist2_to_line( Line(hole,bounce_point), otherLine.p ) )
	            minimumDistance = min( minimumDistance, dist2_to_line( Line(hole,bounce_point), otherLine.q ) )
	    sys.stderr.write("Minimum distance to an object: sqrt(" + str(minimumDistance) + ").\n")
	    
	    return True


print("YES" if do_case() else "NO")

import java.util.Scanner;

public class HoleDarcy {
  public static void main(String[] args) {
    new HoleDarcy().run();
  }

  void run() {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int W = in.nextInt();
    int H = in.nextInt();

    Point ball = new Point(in.nextInt(),in.nextInt());
    Point hole = new Point(in.nextInt(),in.nextInt());

    Line[] A = new Line[n+4];

    for(int i=0; i<n; i++)
      A[i] = new Line( new Point(in.nextInt(),in.nextInt()),
        new Point(in.nextInt(),in.nextInt()) );

    A[n++] = new Line( new Point(0,0), new Point(W,0) );
    A[n++] = new Line( new Point(0,0), new Point(0,H) );
    A[n++] = new Line( new Point(W,H), new Point(W,0) );
    A[n++] = new Line( new Point(W,H), new Point(0,H) );

    boolean ans = false;

    // Shoot straight into the hole
    boolean straight_in = true;
    for(int i=0; i<n; i++)
      if(intersect(new Line(ball,hole),A[i]) != 0)
        straight_in = false;

    if(straight_in)
      ans = true;

    for(int i=0; i<n; i++) {
      int where_hole = orientation(A[i],hole);
      int where_ball = orientation(A[i],ball);
      if(where_hole == 0 || where_ball == 0) continue;
      if(where_hole != where_ball) continue; // No bounce since opposite side

      int ctr = 0; // If this becomes 2, then nothing is in the way!

      for(int dd=0; dd<2; dd++) {
        Pair mirror_mult = reflect(hole,A[i]);
        Point mirror = mirror_mult.p;
        long mult = mirror_mult.d;

        for(int j=0; j<n; j++) {
          A[j].p.x *= mult;
          A[j].p.y *= mult;
          A[j].q.x *= mult;
          A[j].q.y *= mult;
        }

        hole.x *= mult;
        hole.y *= mult;
        ball.x *= mult;
        ball.y *= mult;

        Line shot = new Line(ball,mirror);

        if(intersect(A[i],shot) % 2 == 1) { // Make sure we bounce
          boolean in_the_way = false;
          for(int j=0; j<n; j++)
            if(i != j && intersect(shot,A[j]) != 0 && !intersects_first(shot,A[i],A[j]))
              in_the_way = true;
          if(!in_the_way) ctr++;
        }
        for(int j=0; j<n; j++) {
          A[j].p.x /= mult;
          A[j].p.y /= mult;
          A[j].q.x /= mult;
          A[j].q.y /= mult;
        }

        hole.x /= mult;
        hole.y /= mult;
        ball.x /= mult;
        ball.y /= mult;

        Point tmp = ball;
        ball = hole;
        hole = tmp;
      }
      if(ctr == 2)
        ans = true;
    }

    System.out.println(ans ? "YES" : "NO");
  }

  class Point {
    public long x,y;
    public Point(long x,long y) {
      this.x = x;
      this.y = y;
    }
  }

  class Line {
    Point p,q;
    public Line(Point p,Point q) {
      this.p = p;
      this.q = q;
    }
  }
  Point sub(Point p,Point q) {
    return new Point(p.x-q.x,p.y-q.y);
  }

  Point add(Point p,Point q) {
    return new Point(p.x+q.x,p.y+q.y);
  }

  long cross(Point p,Point q) {
    return p.x*q.y - q.x*p.y;
  }

  // Where is r in comparison to L?
  int orientation(Line L,Point r) {
    long c = cross(sub(L.p,L.q),sub(r,L.q));
    if(c == 0) return 0;
    return (c < 0 ? -1 : 1);
  }

  // Checks if p is on L (assumes p is collinear with L)
  boolean on_segment(Line L, Point p) {
    Point p1 = L.p, p2 = L.q, p3 = p;
    return ((p1.x <= p3.x && p3.x <= p2.x) || (p2.x <= p3.x && p3.x <= p1.x)) &&
           ((p1.y <= p3.y && p3.y <= p2.y) || (p2.y <= p3.y && p3.y <= p1.y));
  }

  // Determines if 2 line segments intersect
  //  - 0 == no intersections
  //  - 1 == interior intersection
  //  - 2 == intersection at endpoint of L1
  //  - 3 == intersection at endpoint of L2 (and not endpoint of L1)
  int intersect(Line L1, Line L2) {
    int d1 = orientation(L2,L1.p), d2 = orientation(L2,L1.q);
    int d3 = orientation(L1,L2.p), d4 = orientation(L1,L2.q);

    if(d1 == 0 && on_segment(L2,L1.p)) return 2;
    if(d2 == 0 && on_segment(L2,L1.q)) return 2;
    if(d3 == 0 && on_segment(L1,L2.p)) return 3;
    if(d4 == 0 && on_segment(L1,L2.q)) return 3;

    if(d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0) return 0;

    return (d1 == -d2 && d3 == -d4) ? 1 : 0; // Either 0 or 1
  }

  boolean lt(long n1,long d1,long n2,long d2) {
    long whole1 = n1 / d1, whole2 = n2 / d2;
    if(whole1 != whole2) return whole1 < whole2;

    n1 %= d1;
    n2 %= d2;
    if(n2 == 0) return false;
    if(n1 == 0) return true;

    return lt(d2,n2,d1,n1);
  }

  // - Returns true if L1 intersects L strictly before L2.
  // - (L and L1) are not collinear, but the other pairs may be.
  // - We know that L intersects both L1 and L2.
  boolean intersects_first(Line L,Line L1,Line L2) {
    long num1 = cross(sub(L1.q,L1.p),sub(L.p,L1.p));
    long num2 = cross(sub(L2.q,L2.p),sub(L.p,L2.p));
    long den1 = cross(sub(L.q,L.p),sub(L1.q,L1.p));
    long den2 = cross(sub(L.q,L.p),sub(L2.q,L2.p));

    if(den2 != 0) // If L and L2 are not collinear
      return lt(num1,den1,num2,den2);

    // Check the endpoints of L2
    Point[] poss = {L2.p,L2.q};
    for(Point end : poss) {
      if(L.p.x != L.q.x) {
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

  class Pair {
    public Point p;
    public long d;
    Pair(Point p,long d) {
      this.p = p;
      this.d = d;
    }
  }

  // The reflected point is ans.first/ans.second
  Pair reflect(Point p,Line L) {
    long b = L.p.x - L.q.x, a = L.q.y - L.p.y, c = cross(L.q,L.p);
    long nx = b * (b*p.x - a*p.y) - a*c;
    long ny = a * (a*p.y - b*p.x) - b*c;
    long d = a*a + b*b;
    return new Pair(new Point(2*nx - d*p.x,2*ny - d*p.y),d);
  }
}

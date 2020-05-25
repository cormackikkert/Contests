#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second

const char nl = '\n';

typedef long double coord_t;
const long double EPS = 1e-15;

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }
template <typename T> T tabs(T val) { return val < T(0) ? -val : val; }
template <typename T> bool eq(T lhs, T rhs, T eps) { return tabs(lhs - rhs) <= EPS * max(tabs(lhs), tabs(rhs)); }

struct Point {
	coord_t x, y;
	Point() : x(0), y(0) {}
	Point(coord_t x, coord_t y) : x(x), y(y) {}
	Point operator+(const Point& rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	Point operator-(const Point& rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	Point operator*(const coord_t rhs) const {
		return Point(x * rhs, y * rhs);
	}
	Point operator/(const coord_t rhs) const {
		return Point(x / rhs, y / rhs);
	}
	coord_t operator*(const Point& rhs) const {
		return (x * rhs.x) + (y * rhs.y);
	}
	coord_t cross(const Point& rhs) const {
		return (x * rhs.y) - (y * rhs.x);
	}
	Point norm() {
		return Point(-y, x);
	}
	coord_t sqmag() {
		return x*x + y*y;
	}
	coord_t mag() {
		return sqrt(sqmag());
	}
	Point unit() {
		coord_t m = mag();
		return Point(x/m, y/m);
	}
	bool operator<(const Point& rhs) const {
		if (x == rhs.x) return y < rhs.y;
		else return x < rhs.x;
	}
	bool operator>(const Point& rhs) const {
		if (x == rhs.x) return y > rhs.y;
		else return x > rhs.x;
	}
	bool operator==(const Point& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator!=(const Point& rhs) const {
		return x != rhs.x || y != rhs.y;
	}
	friend ostream& operator<<(ostream& os, const Point& rhs) {
		os << "(" << rhs.x << ", " << rhs.y << ")";
		return os;
	}
};

struct Line {
	Point s, e;
	Line() : s(), e() {}
	Line(Point s, Point e) : s(s), e(e) {}
	Point vel() {
		return e - s;
	}
	friend ostream& operator<<(ostream& os, const Line& rhs) {
		os << rhs.s << " - " << rhs.e;
		return os;
	}
	bool contains(Point pt) {
		if (s == e) return pt == s;
		Point proj = Point((pt - s) * vel(), (pt - s) * vel().norm()) / vel().sqmag();
		if (0 <= proj.x && proj.x <= 1) proj.x = 0;
		else if (proj.x > 1) proj.x -= 1;
		return proj.mag() <= EPS;
	}
	Point project(Point pt) {
		if (s == e) return pt;
		Point proj = Point((pt - s) * vel(), (pt - s) * vel().norm()) / vel().sqmag();
		return proj;
	}
	pair<bool, Line> intersection(Line rhs) {
		Line lhs = *this;
		Point lv = lhs.vel(), rv = rhs.vel();
		coord_t den = lv.cross(rv);
		Point num = (lv * rhs.s.cross(rhs.e) - rv * lhs.s.cross(lhs.e)) * sgn(den);
		den *= sgn(den);
		if (den == 0) {	// Parallel or Point
			if (lv.cross(rhs.s-lhs.s) == 0 && rv.cross(lhs.s-rhs.s) == 0) {	// Collinear or Point
				if (lhs.s > lhs.e) swap(lhs.s, lhs.e);
				if (rhs.s > rhs.e) swap(rhs.s, rhs.e);
				Line result(max(lhs.s, rhs.s), min(lhs.e, rhs.e));
				if (result.s > result.e) {
					return pair<bool, Line>(false, Line());
				} else {
					return pair<bool, Line>(true, result);
				}
			} else {
				return pair<bool, Line>(false, Line());
			}
		} else {
			Point inter = num / den;
			return pair<bool, Line>(lhs.contains(inter) && rhs.contains(inter), Line(inter, inter));
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, W, H;
	cin >> N >> W >> H;
	Point b, h;
	cin >> b.x >> b.y;
	cin >> h.x >> h.y;
	vector<Line> ls(N);
	bool flag = true;
	for (auto& l : ls) {
		cin >> l.s.x >> l.s.y >> l.e.x >> l.e.y;
		if (l.intersection(Line(b, h)).fst) flag = false;
	}
	if (flag) {
		cout << "YES" << nl;
		return 0;
	}
	ls.push_back(Line(Point(0, 0), Point(W, 0)));
	ls.push_back(Line(Point(W, 0), Point(W, H)));
	ls.push_back(Line(Point(W, H), Point(0, H)));
	ls.push_back(Line(Point(0, H), Point(0, 0)));
	for (int i = 0; i < ls.size(); ++i) {
		Point pb = ls[i].project(b), ph = ls[i].project(h);
		if (sgn(pb.y) * sgn(ph.y) <= 0) continue;
		coord_t r = (pb.y * ph.x + ph.y * pb.x) / (pb.y + ph.y);
		if (r < EPS || coord_t(1)-EPS < r) continue;
		Point m = ls[i].s + ls[i].vel() * r;
		Line bm(b, m), mh(m, h);
		flag = true;
		for (int j = 0; j < ls.size(); ++j) if (i != j) {
			if (bm.intersection(ls[j]).fst || mh.intersection(ls[j]).fst) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "YES" << nl;
			return 0;
		}
	}
	cout << "NO" << nl;
	return 0;
}

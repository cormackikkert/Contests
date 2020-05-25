#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define sz(x) (int)x.size()

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;
using ld = long double;

typedef ld T;
namespace Point3D {
	typedef array<T,3> P3;
	typedef vector<P3> vP3;
	T norm(const P3& x) { 
		T sum = 0; F0R(i,sz(x)) sum += x[i]*x[i];
		return sum;
	}
	T abs(const P3& x) { return sqrt(norm(x)); }
	
	P3& operator+=(P3& l, const P3& r) { 
		F0R(i,3) l[i] += r[i]; return l; }
	P3& operator-=(P3& l, const P3& r) { 
		F0R(i,3) l[i] -= r[i]; return l; }
	P3& operator*=(P3& l, const T& r) { 
		F0R(i,3) l[i] *= r; return l; }
	P3& operator/=(P3& l, const T& r) { 
		F0R(i,3) l[i] /= r; return l; }
	P3 operator+(P3 l, const P3& r) { return l += r; }
	P3 operator-(P3 l, const P3& r) { return l -= r; }
	P3 operator*(P3 l, const T& r) { return l *= r; }
	P3 operator*(const T& r, const P3& l) { return l*r; }
	P3 operator/(P3 l, const T& r) { return l /= r; }
	
	T dot(const P3& a, const P3& b) { 
		T sum = 0; F0R(i,3) sum += a[i]*b[i];
		return sum;
	}
	P3 cross(const P3& a, const P3& b) {
		return {a[1]*b[2]-a[2]*b[1],
				a[2]*b[0]-a[0]*b[2],
				a[0]*b[1]-a[1]*b[0]};
	}
	bool isMult(const P3& a, const P3& b) {
		auto c = cross(a,b); 
		F0R(i,sz(c)) if (c[i] != 0) return 0; 
		return 1;
	}
	bool collinear(const P3& a, const P3& b, const P3& c) { 
		return isMult(b-a,c-a); }
	bool coplanar(const P3& a, const P3& b, const P3& c, const P3& d) { 
		return isMult(cross(b-a,c-a),cross(b-a,d-a)); }
}
using namespace Point3D;

ld dist_point_line(P3 p, P3 a, P3 b) {
    return norm(cross(p - a, b - a)) / norm(b - a);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N;
    ll X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
    P3 TL = P3 {X1, Y1, 0};
    P3 TR = P3 {X2, Y1, 0};
    P3 BL = P3 {X1, Y2, 0};
    P3 BR = P3 {X2, Y2, 0};
    vector<pair<P3, P3>> rect = {{TL, TR}, {TL, BL}, {TR, BR}, {BL, BR}};

    vector<pair<ld, ld>> segs;
    F0R(i, N) {
        ll RX, RY, VX, VY; cin >> RX >> RY >> VX >> VY;
        P3 POS = P3 {RX, RY, 0};
        P3 VEL = P3 {VX, VY, 0};
        vector<ld> times (4);
        for (auto side : rect) {
            
        }
    }
}
#pragma GCC optimized("-O3")
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

#define ld __float128
using ll = long long;
ld INF = LLONG_MAX;

using vld = vector<ld>;
#define pii pair<__float128, __float128>;

vector<ld> px;
vector<ld> py;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return (ld) pow((long double)( x1 - x2), 2) + pow((long double)(y1 - y2), 2);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N; cin >> N;
    
    px = vector<ld> (N);
    py = vector<ld> (N);

    F0R(i, N) {
        ll a, b; cin >> a >> b;
        px[i] = a;
        py[i] =b;
    }

    long double best = INF;
    F0R(i, N) {
        FOR(j, i+1, N) {
            FOR(k, j+1, N) {
                ld ax = px[i];
                ld ay = py[i];
                ld bx = px[j];
                ld by = py[j];
                ld cx = px[k];
                ld cy = py[k];
                ld d = 2 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
                
                ld xc = ((ax * ax + ay * ay) * (by - cy) + (bx * bx + by * by) * (cy - ay) + (cx * cx + cy * cy) * (ay - by)) / (ld) d;
                ld yc = ((ax * ax + ay * ay) * (cx - bx) + (bx * bx + by * by) * (ax - cx) + (cx * cx + cy * cy) * (bx - ax)) / (ld) d;
                ld radius = dist(ax, ay, xc, yc);

                bool fail = false;
                F0R(o, N) {
                    ld xp = px[o];//point.first;
                    ld yp = py[o];//point.second;

                    if (dist(xp, yp, xc, yc) > radius + 1e-6) fail = true;
                }
                if (!fail) {
                    best = min(best, sqrt((long double) radius));
                }
            }
        }
    }
    if (N == 2) {
        ld x1 = px[0];
        ld x2 = px[1];//points[1].first;
        ld y1 = py[0];//points[0].second;
        ld y2 = py[1];//points[1].second;
        cout <<  (long double) sqrt((long double) dist(x1, y1, x2, y2)) / (long double) 2.0 << endl;
    } else {
        cout << (long double) best << endl;
    }
    
}
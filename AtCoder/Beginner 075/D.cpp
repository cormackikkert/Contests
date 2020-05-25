#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, K; cin >> N >> K;
    vll xs (N);
    vll ys (N);
    F0R(i, N) cin >> xs[i] >> ys[i];

    ll area = INF; 
    FOR(i, 0, N) {
        FOR(j, i+1, N) {
            ll l = min(xs[i], xs[j]);
            ll r = max(xs[i], xs[j]);

            FOR(k, 0, N) {
                if (!(l <= xs[k] && xs[k] <= r)) continue;    
                FOR(m, k+1, N) {
                    if (!(l <= xs[m] && xs[m] <= r)) continue;
                    ll u = min(ys[k], ys[m]);
                    ll d = max(ys[k], ys[m]);

                    int inside = 0;
                    F0R(p, N) {
                        if (l <= xs[p] && xs[p] <= r && u <= ys[p] && ys[p] <= d) ++inside;
                    }
                    if (inside >= K) {
                        area = min(area, (r-l) * (d-u));
                    }
                }
            }
        }
    }
    cout << area << endl;
}

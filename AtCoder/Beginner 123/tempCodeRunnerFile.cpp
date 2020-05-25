#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = 1LL << 60;
 
using vc = vector<char>;
using vi = vector<int>;

using comb = tuple<int, int, int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vi XS (X);
    vi YS (Y);
    vi ZS (Z);
    
    F0R(i, X) cin >> XS[i];
    F0R(i, Y) cin >> YS[i];
    F0R(i, Z) cin >> ZS[i];
    sort(XS.begin(), XS.end());
    sort(YS.begin(), YS.end());
    sort(ZS.begin(), ZS.end());
    set<comb> considered;
    priority_queue<pair<ll, comb>, vector<pair<ll, comb>>, greater<pair<ll, comb>>> q;
    q.push({XS[0] + YS[0] + ZS[0], make_tuple(0, 0, 0)});
    considered.insert(make_tuple(0, 0, 0));

    vector<ll> ans (K);
    F0R(i, K) {
        
        comb other = q.top().second;
        int xind = get<0>(other);
        int yind = get<1>(other);
        int zind = get<2>(other);
        ans[i] = q.top().first;
        // cout << q.top().first << " " << q.size() << " " << xind << " " << yind << " " << zind << endl;

        q.pop();
        F0R(xp, 2) {
            F0R(yp, 2) {
                F0R(zp, 2) {
                    if (xp + yp + zp != 1) continue;
                    
                    int nx = xind + xp;
                    int ny = yind + yp;
                    int nz = zind + zp;

                    comb tup = make_tuple(nx, ny, nz);
                    if (nx < X && ny < Y && nz < Z && considered.find(tup) == considered.end()) {
                        q.push({(ll)XS[nx] + YS[ny] + ZS[nz], tup});
                        considered.insert(tup);
                    }
                }
            }
        }
    }
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        cout << *it << endl;
    }
    
}
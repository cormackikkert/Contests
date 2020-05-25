#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, K; cin >> N >> K;
	vll arr (N);
	F0R(i, N) cin >> arr[i];

	map<int, int> occ;
    F0R(i, N) occ[arr[i]] = 0;
    vector<int> res;
    F0R(i, K) {
        for (int x : arr) {
            if (occ[x] == 1) {
                while (occ[x] == 1) {
                    occ[res.back()]--;
                    res.pop_back();
                }
            } else {
                occ[x]++;
                res.emplace_back(x);
            }
        }
        
    }
	for (ll x : res) cout << x << " ";
	cout << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N, K; cin >> N >> K;

    vi HS (N);
    F0R(i, N) cin >> HS[i];

    sort(HS.begin(), HS.end(), greater<ll>());
    
    ll ans = 0;
    for (ll i = K; i < N; ++i) {
        ans += HS[i];
    }

    cout << ans << endl;
}
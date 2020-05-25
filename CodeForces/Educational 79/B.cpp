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

void solve() {
    int N, S; cin >> N >> S;
    vi arr (N+1);
    F0R(i, N) cin >> arr[i+1];

    vll cumsum (N+1);
    FOR(i, 1, N+1) cumsum[i] = arr[i-1] + cumsum[i-1];

    ll best = 0;
    F0R(s, N+1) {
        int l = 0;
        int r = N;
        while (l < r) {
            int mid = l + (r - l) / 2;
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    F0R(i, T) solve();
}
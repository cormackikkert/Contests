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
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    vector<pii> arr (N);
    F0R(i, N) {int a, b; cin >> a >> b; arr[i] = {a, b};}

    ll ans = 0;
    ll small = INF;
    for (auto pr : arr) {
        ans += pr.first;
        if (pr.first > pr.second) small = min(small, (ll) pr.second);
    }

    bool valdiff = false;
    for (auto pr : arr) valdiff |= (pr.first != pr.second);
    cout << ((valdiff) ? ans - small: 0) << endl;
}
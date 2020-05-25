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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll I, O, T, J, L, S, Z; cin >> I >> O >> T >> J >> L >> S >> Z;
    ll ans = 0;
    ans += O;
    if (((I % 2) + (J % 2) + (L % 2) >= 2) && I > 0 && J > 0 && L > 0) {
        ans += 3;
        --I; --J; --L;
    } 
    ans += I / 2 * 2;
    ans += J / 2 * 2;
    ans += L / 2 * 2;
    cout << ans << endl;
}
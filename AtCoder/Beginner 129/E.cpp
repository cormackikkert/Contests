#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
ll MOD = 1e9 + 7;

using vc = vector<char>;
using vi = vector<int>;

string L;
vector<vector<ll>> dp;

ll get_count(int sIndex, bool isUnder) {
    if (sIndex == L.size()) return 1;

    if (dp[sIndex][isUnder] != -1) return dp[sIndex][isUnder];
    
    ll ways = 0;
    // add 0
    ways += get_count(sIndex + 1, isUnder | (L[sIndex] == '1'));
    
    // add 1
    if (isUnder) {
        ways += 2 * get_count(sIndex + 1, isUnder);
    } else if (L[sIndex] == '1') {
        ways += 2 * get_count(sIndex + 1, false);
    }
    ways %= MOD;
    dp[sIndex][isUnder] = ways;
    return ways;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> L;
    dp = vector<vector<ll>> (L.length(), vector<ll>(2, -1));
    cout << get_count(0, false) << endl;
}
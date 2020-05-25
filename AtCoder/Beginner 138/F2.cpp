#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[61][2][2][2];
ll MOD = pow(10, 9) + 7;
ll L, R;

ll recurse(ll digits, ll canLo, ll canHi, ll doneFirst) {
    if (digits == -1)
        return 1;

    if (dp[digits][canLo][canHi][doneFirst] != -1)
        return dp[digits][canLo][canHi][doneFirst];

    ll ways = 0;

    // x 0, y 0
    if (!canLo || !(L & (1LL << digits))) {
        ways += recurse(digits - 1, canLo, canHi && ~(R & (1LL << digits)), doneFirst);
    }
    // x 0, y 1
    if ((!canLo || !(L & (1LL << digits))) &&
        (!canHi || (R & (1LL << digits))) && doneFirst) {
        ways += recurse(digits - 1, canLo, canHi, doneFirst);
    }
    // x 1, y 1
    if (!canHi || (R & (1LL << digits))) {
        ways += recurse(digits - 1, canLo && (L & (1LL << digits)), canHi, true);
    }
    ways %= MOD;

    dp[digits][canLo][canHi][doneFirst] = ways;
    return ways;   
}

int main() {
    for (int i = 0; i <= 60; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                for (int l = 0; l < 2; ++l)
                    dp[i][j][k][l] = -1;
    cin >> L >> R;
    cout << recurse(60, true, true, false) << endl;

}
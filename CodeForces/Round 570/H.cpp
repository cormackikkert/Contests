#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[101][101];
char s[101];

ll recurse(ll m, ll k) {
    if (k == 0) return 1;
    if (m == -1) return 0;
    if (dp[m][k] != -1) return dp[m][k];
    ll t = recurse(m-1, k) + recurse(m-1, k-1);
    for (ll i = m-1; i >= 0; --i) {
        if (s[i] == s[m]) {
            t-=recurse(i-1,k-1); break;
        }
    }
    dp[m][k] = t; 
    return t;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k; cin >> n >> k;
    vector<char> arr (n);
    for (ll i = 0; i < n; ++i) cin >> s[i];
    for (ll i = 0; i <= n; ++i) {
        for (ll j = 0; j <= n; ++j) {
            dp[i][j] = -1;
        }
    }
    recurse(n-1,n);

    ll l = n;
    ll c = 0;
    ll t = 0;
    while (true) {
        if (l < 0) {
            cout << -1 << endl;
            return 0;
        }
        if (recurse(n-1, l) + c >= k) {
            t += (k - c) * (n-l);
            break;
        } else {
            t += (n-l) * recurse(n-1, l);
            c += recurse(n-1, l);
            --l;
        }
    }
    cout << t << endl;
    
}
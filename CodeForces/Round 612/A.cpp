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

void solve() {
    int K; cin >> K;
    string s; cin >> s;

    int best = 0;
    F0R(i, K) {
        if (s[i] == 'A') {
            int j = i;
            while (j + 1 < K && s[j + 1] == 'P') ++j;

            best = max(j - i, best);
            i = j;
        }
    }
    cout << best << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    F0R(i, T) solve();
}
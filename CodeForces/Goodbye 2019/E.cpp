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

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    vi XS (N);
    vi YS (N);

    vi ans;
    F0R(i, N) cin >> XS[i] >> YS[i];
    FOR(i, 1, N) {
        if (gcd(abs(XS[i] - XS[0]), abs(YS[i] - YS[0])) == 1) {
            ans.push_back(i+1);
        }
    }
    if (ans.size() == 0) ans.push_back(1);
    
    cout << ans.size() << endl;
    F0R(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
}
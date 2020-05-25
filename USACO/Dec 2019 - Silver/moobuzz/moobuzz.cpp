#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)


ll INF = 1LL << 60;
 
using vc = vector<char>;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);

    ll N; cin >> N;

    vi digits = {1, 2, 4, 7, 8, 11, 13, 14};
    cout << (N / 8) * 15 + digits[(N-1)%8] << endl;
}
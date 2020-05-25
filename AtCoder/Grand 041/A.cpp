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
    ll N, A, B;
    cin >> N >> A >> B;
    if (abs(A-B) % 2 == 0) {
        cout << abs(A-B) / 2 << endl;
    } else {
        cout << min(A + abs(1 - (B-(A-1)-1)) / 2,
                    N-B+1 + abs(N - (A+(N-B)+1)) / 2) << endl;
    }
}
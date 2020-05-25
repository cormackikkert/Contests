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
    ll N; cin >> N;
    if (N%2 == 1) {
        cout << 0 << endl;
    } else {
        ll count = 0;
        count += N / 10;
    
        for (ll five = 5; N >= 10 * five; five *= 5) {
            count += N / (10 * five);
        }
        cout << count << endl;
    }
}
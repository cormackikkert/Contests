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
using vb = vector<int>;
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin >> n >> k;
    vb isPrime (1e5, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i * i <= 1e5; ++i) {
        if (isPrime[i]) {
            for (int j = 2*i; j < 1e5; j += i)
                isPrime[j] = false;
        }
    }
    ll ans = 0;
    vector<map<vi, int>> occ ((int)(1e5+1), map<vi, int>());
    F0R(i, n) {
        int num; cin >> num;
        vi factors;
        for (int f = 1; f * f < 1e5; ++f) {
            if (!isPrime[f]) continue;
            int c = 0;
            while (num % f == 0) {++c; num /= f;}
            c %= k;
            factors.push_back(c);
        }

        vi other;
        for (int f : factors) other.push_back((k - f) % k );
        //cout << "ADDING: " << occ[num][other] << endl;
        if ((k == 2 || num == 1) && (occ[num].find(other) != occ[num].end())) {ans += occ[num][other];}
        occ[num][factors]++;
    }
 
    cout << ans << endl;
}
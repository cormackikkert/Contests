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
using vll = vector<ll>;

ll N, K;
int MAX_DIGITS = 40;
vi digitCount (MAX_DIGITS);
vector<vll> dp (MAX_DIGITS, vll (2, -1));
vll nums;
ll recurse(int digitpos, bool less) {
    if (digitpos < 0) return 0;
    if (dp[digitpos][less] != -1) return dp[digitpos][less];

    // place 1
    ll best = 0;
    if (less || (K & (1LL << digitpos))) {
        best = max(best, (1LL << digitpos) * (N-digitCount[digitpos]) + recurse(digitpos - 1, less));
    }

    // place 0
    best = max(best, (1LL << digitpos) * digitCount[digitpos] + recurse(digitpos - 1, less | (K & (1LL << digitpos))));

    dp[digitpos][less] = best;
    return best;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    
    cin >> N >> K;

    nums.resize(N);

    F0R(i, N) {
        ll num; cin >> num;
        nums[i] = num;
        F0R(d, MAX_DIGITS) {
            digitCount[d] += num % 2;
            num /= 2;
        }
    }
    cout << recurse(39, false) << endl;
}
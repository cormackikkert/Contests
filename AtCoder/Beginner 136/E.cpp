#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;

using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;

int N, K;
vi arr;

bool isPossible(int factor) {
    vi res (N);
    F0R(i, N) {
        res[i] = arr[i] % factor;
    }
    sort(res.begin(), res.end());

    vll lcum (N+1);
    vll rcum (N+1);
    F0R(i, N) lcum[i+1] = lcum[i] + res[i];
    R0F(i, N) rcum[i] = rcum[i+1] + res[i];
    ll moves = K + 1;
    F0R(i, N+1) {
        ll RHS = (N-i) * factor - rcum[i];
        if (abs(lcum[i] - RHS) % factor == 0) {
            moves = min(moves, max(lcum[i], RHS));
        }
    }
    return moves <= K;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    arr.resize(N);
    F0R(i, N) cin >> arr[i];
    
    int total = 0;
    F0R(i, N) total += arr[i];

    ROF(i, 1, total + 1) {
        if (total % i != 0) continue;
        if (isPossible(i)) {
            cout << i << endl;
            return 0;
        }
    }
}
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

pair<int, int> canDo(vi arr) {
    F0R(i, arr.size()) arr[i] -= i;
    int MINV = arr[0];
    int MINI = 0;
    FOR(i, 1, arr.size()) {
        if (arr[i] - MINV >= 0) {
            return {MINI, i};
        }
        if (arr[i] < MINV) {
            MINV = arr[i]; MINI = i;
        }
    }
    return {-1, -1};
}
void solve() {
    // im retarded
    int N; cin >> N;
    vi arr (N);
    F0R(i, N) cin >> arr[i];
    FOR(i, 1, N) {
        if (abs(arr[i] - arr[i-1]) > 1) {
            cout << "YES\n";
            cout << i << " " << i + 1 << '\n';
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    F0R(i, T) solve();
}
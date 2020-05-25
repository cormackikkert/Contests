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
    int N; cin >> N;
    vector<vc> grid (N, vc (N));
    F0R(i, N) {
        F0R(j, N) { 
            cin >> grid[i][j];
        }
    }

    ll ans = 0;
    F0R(i, N) {
        vector<vc> symmetric_grid (N, vc (N));
        F0R(y, N) {
            F0R(x, N) {
                symmetric_grid[y][x] = grid[y][(x+i)%N];
            }
        }
        bool isSymmetric = true;
        F0R(y, N){ 
            F0R(x, N) {
                if (symmetric_grid[y][x] != symmetric_grid[x][y]) isSymmetric=  false;
            }
        }
        if (!isSymmetric) continue;
        ans += N;
    }
    cout << ans;
}
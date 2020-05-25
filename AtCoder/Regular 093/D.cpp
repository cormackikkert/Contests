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

int A, B;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> A >> B;
    int lo = min(A, B); int hi = max(A, B);
    const int S = 97;
    vector<bitset<S>> grid (97);
    lo -= 1;
    for (int i = 1; i + 3 < S; i += 4) {
        for (int j = 1; j + 3 < S; j += 4) {
            if (hi > 0) {
                F0R(x,3) F0R(y, 3) grid[i+y][j+x] = true;
                --hi;
            }
            if (lo > 0) {
                grid[i+1][j+1] = false;
                --lo;
            }
        }
    }
    cout << S << " " << S << endl;
    F0R(i, S) {
        F0R(j, S) {
            cout << ((grid[i][j] != (max(A, B) == A)) ? '#' : '.');
        }
        cout << endl;
    }
}
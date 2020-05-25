#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
 
using ll = long long;
ll INF = 1LL << 60;
int MOD = 1e9+7;
 
using vc = vector<char>;
using vi = vector<int>;
using vb = vector<bool>;
 
void modify(vi& tree, int i, int v) {
    i += tree.size()/2;
    tree[i] = v;
    for (i /= 2; i >= 1; i /= 2) {tree[i] = tree[2*i] + tree[2*i+1]; tree[i] %= MOD;}
}
 
int query(vi& tree, int a, int b) {
    a += tree.size() / 2; b += tree.size() / 2;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) {s += tree[a++]; s %= MOD;}
        if (b % 2 == 0) {s += tree[b--]; s %= MOD;}
        a /= 2; b /= 2;
    }
    return s;
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vb> grid (n, vb (m));
    F0R(i, n) {
        F0R(j, m) {
            char c; cin >> c;
            grid[i][j] = (c == 'R');
        }
    }
 
    vector<vi> rowsums(n, vi (m+1));
    vector<vi> colsums(m, vi (n+1));
    vector<vi> rowdp (n, vi (2*m));
    vector<vi> coldp (m, vi (2*n));
 
    F0R(i, n) {
        int t = 0;
        R0F(j, m) {
            t += grid[i][j];
            rowsums[i][j] = t;
        }
    }
    F0R(j, m) {
        int t = 0;
        R0F(i, n) {
            t += grid[i][j];
            colsums[j][i] = t;
        }
    }
 
    R0F(i, n) {
        R0F(j, m) {
            // (Down, Right)
            for (int d : {-1, 1}) {
                int ans;
                if (i == n - 1 && j == m - 1) ans = 1;
                else if (i == n - 1) ans = (rowsums[i][j+1] == 0 && d == 1);
                else if (j == m - 1) ans = (colsums[j][i+1] == 0 && d == -1);
                else {
                    if (d == -1) {
                        ans = query(coldp[j], i+1, n-1-colsums[j][i+1]);
                    } else {
                        ans = query(rowdp[i], j+1, m-1-rowsums[i][j+1]);
                    }
                }
                // Save
                if (d == -1) {
                    modify(rowdp[i], j, ans);
                } else {
                    modify(coldp[j], i, ans);
                }
            }            
        }
    }
 
    int res = query(rowdp[0], 0, 0) + query(coldp[0], 0, 0); 
    if (n == 1 && m == 1)
        cout << res/2 << endl;
    else 
        cout << res % MOD << endl;
}
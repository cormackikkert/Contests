#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
ll MOD = 31337;

using vc = vector<char>;
using vi = vector<int>;

vector<vi> mult(vector<vi>& A, vector<vi>& B) {
    vector<vi> ans (A.size(), vi (B[0].size()));

    F0R(y, A.size()) {
        F0R(x, B[0].size()) {
            
            F0R(i, B.size()) {
                ans[y][x] += A[y][i] * B[i][x];
                ans[y][x] %= MOD;  
            }
        }
    }

    return ans;
}

vector<vi> binpow(vector<vi> a, ll b) {
    vector<vi> res (a.size(), vi (a.size()));
    F0R(i, a.size()) res[i][i] = 1;

    while (b > 0) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}



int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    freopen("life.in", "r", stdin);
    freopen("life.out", "w", stdout);

    vector<vi> mat = {{0, 0, 1, 0, 1, 0, 0, 1},
                      {1, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 1, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 0},
                      {0, 0, 0, 0, 1, 0, 0, 0},
                      {0, 0, 0, 0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 0, 0, 1, 0}};

    ll n; cin >> n;
    vector<vi> orig = {{3},
                       {0},
                       {1},
                       {1},
                       {0},
                       {1},
                       {0},
                       {0}};

    if (n >= 8) {
        vector<vi> act = binpow(mat, n-8);
        act = mult(act, orig);
        cout << act[0][0] << endl;
    } else {
        cout << orig[8-n][0] << endl;
    }    

}
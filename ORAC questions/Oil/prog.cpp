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
using vii = vector<vi>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M, K;
    cin >> M >> N >> K;
    
    vii arr (N, vi (N));
    vii pre (N, vi (N, -1));

    int dp[1500][1500][3];

    F0R(i, M) F0R(j, N) cin >> arr[i][j];
    F0R(i, M) {
        F0R(j, N) {
            int oL = (j > 0) ? pre[i][j-1] : 0;
            int oT = (i > 0) ? pre[i-1][j] : 0;
            pre[i][j] = oL + oT + arr[i][j]; 
        }
    }

    F0R(r, 3) {
        F0R(i, M) {
            F0R(j, N) {
                
            }
        }
    }
}
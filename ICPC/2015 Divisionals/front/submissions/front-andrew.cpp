#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define CL(x) memset(x, 0, sizeof(x))

const int N = 100005, H = 105;
int n, h, a;
double pd, pa, pu, dp[N][H], A[N][H];

int main() {
    cin >> n >> h >> a >> pd >> pa >> pu;
    pd /= 100.0;
    pa /= 100.0;
    pu /= 100.0;

    CL(dp); CL(A);
    dp[0][a] = 1.0;
    for (int i = 0; i < n; i++) {
      for (int y = 0; y <= h; y++) {
        dp[i+1][min(h,y+1)] += dp[i][y] * pu;
        dp[i+1][y]          += dp[i][y] * pa;
        dp[i+1][max(0,y-1)] += dp[i][y] * pd;

        A[i+1][min(h,y+1)] += (A[i][y] + dp[i][y]*(y + min(h,y+1))/2.0) * pu;
        A[i+1][y]          += (A[i][y] + dp[i][y]*(y + y  )/2.0) * pa;
        A[i+1][max(0,y-1)] += (A[i][y] + dp[i][y]*(y + max(0,y-1))/2.0) * pd;
      }
    }

    double ans = 0;
    for (int y = 0; y <= h; y++) ans += A[n][y];
    printf("%0.10lf\n", ans);
}

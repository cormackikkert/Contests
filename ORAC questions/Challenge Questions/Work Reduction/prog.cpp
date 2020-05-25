#include <bits/stdc++.h>
#include <string>
#include <climits>

using namespace std;

long min(long a, long b) {
  if (a < b) {
    return a;
  }
  return b;
}

int main() {
  freopen("work.in","r",stdin);
  // freopen("work.out","w",stdout);
  int cases;
  scanf("%d", &cases);
  for (int i = 0; i < cases; i++) {
    int N, M, L;
    printf("Case %d\n", i);
    scanf("%d %d %d", &N, &M, &L);
    int dp[N-M+1];
    for (int j = 0; j < L; j++) {
      char agency[17];
      int a, b;
      scanf("%16[^:]", agency);
      printf("name %s\n", agency);
      scanf("%d,%d", &a, &b);
      // printf("values %d %d\n", &a, &b);
      dp[0] = 0;
      for (int k = M + 1; k <= N+1; k++) {
        if ((k >> 1) >= M) {
          dp[k-M] = min(dp[k-1-M] + a, dp[(k >> 1) -M] + b);
        } else {
          dp[k-M] = dp[k-1-M] + a;
        }
        //printf("%d\n", &dp[k-M]);
      }
      //printf("%s %d\n",agency, &dp[N-M+1]);
    }
  }
  return 0;
}

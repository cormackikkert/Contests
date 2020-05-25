#include <bits/stdc++.h>
#include <climits>

using namespace std;

long s;
long n;
long Taxis[1000][2];
long min(long a, long b) {
  if (a < b) {
    return a;
  }
  return b;
}
int main() {
  freopen("taxiin.txt","r",stdin);
  freopen("taxiout.txt","w",stdout);

  scanf("%d", &s);
  scanf("%d", &n);

  for (long i = 0; i <= n; i++) {
    long cost;
    long peop;
    scanf("%d", &cost);
    scanf("%d", &peop);

    Taxis[i][0] = cost;
    Taxis[i][1] = peop;
  }

  long dp[s+1];

  dp[0] = 0;

  for (long i = 1; i < s + 1; i++) {
    long best = LONG_MAX;
    for (long j = 0; j < n; j ++) {
      long cost = Taxis[j][0];
      long peop = Taxis[j][1];
      if (peop == i || peop - 1 == i) {
        best = min(best, cost);
      }
      if (i - peop >= 0) {
        best = min(best, dp[i - peop] + cost);
      }
      if (i - peop - 1 >= 0) {
        best = min(best, dp[i - peop + 1] + cost);
      }
    }
    dp[i] = best;
  }
  printf("%d\n", dp[s]);
  return 0;
}

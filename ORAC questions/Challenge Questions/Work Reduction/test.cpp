#include <bits/stdc++.h>
#include <climits>
#include <string>

using namespace std;

int main() {
  freopen("d.in","r",stdin);
  freopen("work.out","w",stdout);
  int a, b;
  char c[101];

  scanf("%d %d %100s", &a, &b, c);
  string ch = str(c);
  printf("%d %d %s", ch, b, a);
  return 0;
}

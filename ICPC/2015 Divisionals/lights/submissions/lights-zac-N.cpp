// Expected: AC
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>


// START CASE 1
// Case where light turns green for the first time after you cross it, but a
// naive implementation might do the maths without checking the first time.
/* IN
1 10
8 10 50 1
*/
/* OUT
NO
*/
// END CASE 1

// START CASE 2
// Case where light turns green for the first time exactly when you cross it.
/* IN
1 10
10 10 1 1
*/
/* OUT
YES
*/
// END CASE 2

// START CASE 3
// Case where lights aren't in sorted order, which an implementation might
// have assumed to be the case (but is not given).
/* IN
5 10
4 4 4 4
5 5 5 5
1 1 1 1
2 2 3 4
5 4 3 2
*/
/* OUT
YES
*/
// END CASE 3


void Yes()
{
  std::cout << "YES" << std::endl;
  exit(0);
}

void No()
{
  std::cout << "NO" << std::endl;
  exit(0);
}

struct Light {
  int d, s, g, r;
};

std::istream &operator>>(std::istream &in, Light &l)
{
  return in >> l.d >> l.s >> l.g >> l.r;
}

int main()
{
  int n, d;
  std::cin >> n >> d;
  std::vector<Light> lights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> lights[i];
  }
  for (Light &l : lights) {
    if (l.d < l.s) No();
    l.d -= l.s;
    l.d %= (l.g + l.r);
    if (l.d <= l.g) continue;
    No();
  }
  Yes();
}

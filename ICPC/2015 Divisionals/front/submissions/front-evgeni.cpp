#include <bits/stdc++.h>
using namespace std;

#define ff(a, b)    for (int a = 0; a < int(b); ++a)
#define yy(n)    ff(y, n)
#define ii(n)    ff(i, n)
#define fff(a, b, c) for (int a = int(b); a < int(c); ++a)

using DD = long double;


// AC intended.
// Just a different way of adding things up.


int main() {
    cout.precision(16);

    int n, h, a;
    vector<DD> Ps(3, 0);
    cin >> n >> h >> a >> Ps[0] >> Ps[1] >> Ps[2];
    ii (3)
        Ps[i] *= 0.01;

    vector<DD> prob(h+1, 0);
    prob[a] = 0.5;
    DD rr = 0;
    ii (n) {
        vector<DD> nextprob(h+1, 0);
        yy (h+1)
            rr += y*prob[y];
        yy (h+1) {
            fff (delta, -1, 2) {
                int ynext = max(0, min(h, y+delta));
                nextprob[ynext] += prob[y] * Ps[delta+1];
            }
        }
        swap(prob, nextprob);
        yy (h+1)
            rr += y*prob[y];
    }

    cout << double(rr) << '\n';
    

    return 0;
}

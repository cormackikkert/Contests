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

bool check(int num, int p) {
    int c = num;

    int total = 0;
    int count = 0;
    for (int i = 0; c > 0; ++i) {
        if (c % 2 != 0) {
            ++count;
            if (total < p) 
                total += pow(2, i);
        }
        c /= 2;
    }
    return (count <= p && total >= p);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, P; cin >> N >> P;

    for (int i = 0;;++i) {
        if (N-i*P < 0) break;
        if (check(N-i*P, i)) {
            cout << i << endl; return 0;
        }
    }
    cout << -1 << endl;
}
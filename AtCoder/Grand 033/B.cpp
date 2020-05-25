#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;

int H, W, N;
int SR, SC; 
string S, T;

bool solveLR() {
    int lo = 0; int hi = W - 1;
    R0F(i, N) {
        if (T[i] == 'L')             
            hi = min(hi+1, W-1);
        if (T[i] == 'R')
            lo = max(lo-1, 0);

        if (S[i] == 'L') ++lo;
        if (S[i] == 'R') --hi;

        if (lo > hi || lo > W - 1 || hi < 0) return false;
    }
    return lo <= SC && SC <= hi;
}

bool solveUD() {
    int lo = 0; int hi = H - 1;
    R0F(i, N) {
        if (T[i] == 'U')             
            hi = min(hi+1, H-1);
        if (T[i] == 'D')
            lo = max(lo-1, 0);

        if (S[i] == 'U') ++lo;
        if (S[i] == 'D') --hi;

        if (lo > hi || lo > H - 1 || hi < 0) return false;
    }
    return lo <= SR && SR <= hi;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> H >> W >> N;
    cin >> SR >> SC; --SR; --SC;
    cin >> S >> T;
    if (solveLR() && solveUD()) cout << "YES" << endl;
    else cout << "NO" << endl;
}
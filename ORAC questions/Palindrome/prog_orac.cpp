#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
 
using vc = vector<char>;
using vi = vector<int>;

int N;
vc S;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    freopen("palin.in", "r", stdin);
    freopen("palin.out", "w", stdout);

    cin >> N;
    S = vc(N);
    F0R(i, N) cin >> S[i];

    vi dpcur (N);
    vi dpold (N);
    
    R0F(i, N-1) {
        F0R(j, N) {
            if (j-i <= 0) {dpcur[j] = 0; continue;}
            int ans = 1 + min(dpcur[j-1], dpold[j]);
            if (S[i] == S[j]) ans = min(ans, dpold[j-1]);
            dpcur[j] = ans;
        }
        dpold = dpcur;
        dpcur = vi(N);
    }
    cout << dpold[N-1] << endl;
}
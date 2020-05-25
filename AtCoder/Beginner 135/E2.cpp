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
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll K, X, Y; cin >> K >> X >> Y;
    if (K%2 == 0 && (X+Y) % 2 != 0) {cout << -1 << endl; return 0;}
 
    ll D = 0;
    ll L = abs(X);
    ll U = abs(Y);
    ll R = 0;
 
    // D L U R
    while (true) {
        printf("%d %d %d %d\n", D, L, U, R);
        bool f1 = ((D % K + L) < K && (D % K > 0) && U > 0);
        bool f2 = (((D+L) % K + U) < K && R > 0 && ((D+L) % K > 0));

        if ((U+L+D+R)%K == 0 && !f1 && !f2) break;
        
        
        if (L > U) {
            ++D; ++U;
        } else if (U > L || f1) {
            ++L; ++R;
        } else {
            ++D; ++U;
        }
    }
    
    cout << (U + L + D + R) / K << endl;
 
    ll CX = 0; 
    ll CY = 0;
    ll SX = 0;
    ll SY = 0;

    ll t = 0;
    while (D--> 0) {
        CY -= (Y > 0) ? 1 : -1;
        if (++t % K == 0) {
            if (abs(CX - SX) + abs(CY - SY) != K) cout << 1/0 << endl;
            SX = CX; SY = CY;
            cout << CX << " " << CY << endl;
        }
    }
 
    while (L--> 0) {
        CX += (X > 0) ? 1 : -1;
        if (++t % K == 0) {
            if (abs(CX - SX) + abs(CY - SY) != K) cout << 1/0 << endl;
            SX = CX; SY = CY;
            cout << CX << " " << CY << endl;
        }
    }   
 
    while (U--> 0) {
        CY += (Y > 0) ? 1 : -1;
        if (++t % K == 0) {
            if (abs(CX - SX) + abs(CY - SY) != K) cout << 1/0 << endl;
            SX = CX; SY = CY;
            cout << CX << " " << CY << endl;
        }
    }
 
    while (R --> 0) {
        CX -= (X > 0) ? 1 : -1;
        if (++t % K == 0) {
            if (abs(CX - SX) + abs(CY - SY) != K) cout << 1/0 << endl;
            SX = CX; SY = CY;
            cout << CX << " " << CY << endl;
        }
    }
}

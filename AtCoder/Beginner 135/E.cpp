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

int round_up(int v, int r) {
    return r * (v / r + (v % r != 0));
}
int solve(int X, int Y, int K) {
   if (K%2 == 0 && (X+Y) % 2 != 0) {return -1;}
 
    ll D = 0;
    ll L = abs(X);
    ll U = abs(Y);
    ll R = 0;
 
    // D L U R
    while (true) {

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
    
    return (U + L + D + R) / K;
}

int solve3(int X, int Y, int K) {
    if (K % 2 == 0 && (abs(X) + abs(Y)) % 2 == 1) {
        return -1;
    }

    int ex = 0;
    int ed = 0;
    int H = max(abs(X), abs(Y));
    int V = min(abs(X), abs(Y));
    
    int diff = round_up(H+V, K) - H - V;
    bool flip = false;
    
    if (diff != 0) {
        if (diff % 2 == 1) H += 1, flip = !flip;
        else ex += diff / 2;
    }

    
    while ((H - ed != max(abs(X), abs(Y))) || ((ed + ex) % K > 0 && (ed + ex) % K + H < K)) {
        cout << ed << " " << ex << " " << H << " " << ex << endl;

        if (K % 2 == 1) {
            if (flip) ++ed;
            else ++H;
            flip = !flip;
        } 
        ex += K / 2;
    }

    cout << ex << " " << H << " " << ex << endl;
    
    return (2 * ex + H + V + ed) / K;
}

int solve2 (int X, int Y, int K) {
    if (K % 2 == 0 && (abs(X) + abs(Y)) % 2 == 1) {
        return -1;
    }
 
    ll curX = 0, curY = 0;
 
    ll ans = (abs(X) + abs(Y) +K-1)/K;
    if (ans == 1 && (abs(X)+abs(Y)) != K) ans++;
    while ((ans*K-abs(X)-abs(Y))%2 != 0) ans++;
 
    ll waste = ans*K; waste -= (abs(X)+abs(Y)); waste /= 2;
    return ans;

}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int K, X, Y; cin >> K >> X >> Y;
    cout << solve3(0, 3, 7) << endl;
    cout << solve2(0, 3, 7) << endl;
    return 0;
    while (true) {
        int X = rand() % 10;
        int Y = rand() % 10;
        int K = rand() % 10 + 1;
        if (solve3(X, Y, K) != solve2(X, Y, K)) {
            cout << X << " " << Y << " " << K << endl;
        }
    }
} 
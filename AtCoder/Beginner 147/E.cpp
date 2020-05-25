#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

ll MAX_SCORE = 26000;
ll SCORE = 13000;
bool dp[85][85][26000];

ll ind(ll i) {
    return (i >= 0) ? i : MAX_SCORE - i;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("text.txt", "r", stdin);
    ll H, W; cin >> H >> W;
    vector<vector<ll>> SC (H, vector<ll>(W));
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            cin >> SC[i][j];
        }
    }
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            ll x; cin >> x;
            SC[i][j] -= x;
        }
    }
    for (ll i = 0; i <= 80; ++i) {
        for (ll j = 0; j <= 80; ++j) {
            for (ll x = -SCORE; x <= SCORE; ++x) {
                dp[i][j][ind(x)] = false;
            }
        }
    }

    dp[0][0][0] = true;
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            for (ll s = -SCORE; s <= SCORE; ++s) {
                if (!dp[i][j][ind(s)]) continue;

               
                if (i + 1 < H) {
                    dp[i+1][j][ind(s + SC[i][j])] = true;
                    dp[i+1][j][ind(s - SC[i][j])] = true;
                }

                if (j + 1 < W) {
                    dp[i][j+1][ind(s + SC[i][j])] = true;
                    dp[i][j+1][ind(s - SC[i][j])] = true;
                }
            }
        }
    }
    ll best = 2*SCORE;
    for (ll s = 0; s <= SCORE; ++s) {
        if (!dp[H-1][W-1][s]) continue;
        best = min(best, abs(s + SC[H-1][W-1]));
        best = min(best, abs(s - SC[H-1][W-1]));
    }
    cout << best << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<uint32_t>;

map<vi, int> occ;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, K; cin >> N >> K;
    vector<vi> allCards;
    F0R(i, N) {
        vi card (K);
        F0R(i, K) {
            char c; cin >> c;
            if (c == 'S') card[i] = 0;
            if (c == 'E') card[i] = 1;
            if (c == 'T') card[i] = 2;
        }
        occ[card] += 1;
        allCards.push_back(card);
    }
    ll ans = 0;
    F0R(i, N) {
        FOR(j,i+1, N) {
            if (i == j) continue;
            if (allCards[i] == allCards[j]) {ans += (occ[allCards[i]] > 2) ? occ[allCards[i]] - 2 : 0; continue;}
            vi c1 = allCards[i];
            vi c2 = allCards[j];
            vi other (K);
            F0R(k, K) {
                if (c1[k] == c2[k]) other[k] = c1[k];
                else other[k] = 3 - c1[k] - c2[k];
            }
            /*cout << "PRINT: " << endl;
            for (vi gay : {c1, c2, other}) {
                cout << "CARD: " << endl;
                F0R(k, K) cout << gay[k] << " ";
                cout << endl;
            }*/
            ans += occ[other];
            
        }
    }
    cout << ans / 3 << endl;
}
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
using vll = vector<ll>;

int N;
ll W;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> W;
    vi weights0;
    vi weights1;
    vi weights2;
    vi weights3;
    ll BW; int BC; cin >> BW; cin >> BC; weights0.push_back(BC);
    F0R(i, N-1) {
        int W, V; cin >> W >> V;
        if (W == BW) weights0.push_back(V); 
        if (W == BW+1) weights1.push_back(V); 
        if (W == BW+2) weights2.push_back(V); 
        if (W == BW+3) weights3.push_back(V); 
    }
    
    sort(weights0.begin(), weights0.end(), greater<int>());
    sort(weights1.begin(), weights1.end(), greater<int>());
    sort(weights2.begin(), weights2.end(), greater<int>());
    sort(weights3.begin(), weights3.end(), greater<int>());

    vll cumsum0 (N+1); cumsum0[0] = 0;
    vll cumsum1 (N+1); cumsum1[0] = 0;
    vll cumsum2 (N+1); cumsum2[0] = 0;
    vll cumsum3 (N+1); cumsum3[0] = 0;

    FOR(i, 1, N+1) {
        if (i <= weights0.size()) cumsum0[i] = weights0[i-1] + cumsum0[i-1];
        if (i <= weights1.size()) cumsum1[i] = weights1[i-1] + cumsum1[i-1];
        if (i <= weights2.size()) cumsum2[i] = weights2[i-1] + cumsum2[i-1];
        if (i <= weights3.size()) cumsum3[i] = weights3[i-1] + cumsum3[i-1];
    }
    
    ll best = 0;
    for (int i = 0; i <= weights0.size(); ++i) {
        for (int j = 0; j <= weights1.size(); ++j) {
            for (int k = 0; k <= weights2.size(); ++k) {
                for (int l = 0; l <= weights3.size(); ++l) {
                    if (i * BW + j * (BW+1) + k * (BW+2) + l * (BW+3) > W) continue;
                    best = max(best, 1LL * cumsum0[i] + cumsum1[j] + cumsum2[k] + cumsum3[l]);
                }
            }
        }
    }
    cout << best << endl;
}
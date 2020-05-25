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
using pii = pair<int, ll>;

vector<vector<pii>> graph (20);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll M = 0;

    FOR(i, 2, 14) {
        ll base = pow(3, 13-i);
        M += 3;
        graph[i].push_back({i+1, 0*base});
        graph[i].push_back({i+1, 1*base});
        graph[i].push_back({i+1, 2*base});
    }
    int L; cin >> L;
    
    ll curOps = pow(3, 13);
    ll index = 1;
    ll base = 0;

    while (base < L && curOps > 1) {
        while (base + curOps > L) {
            curOps /= 3; ++index;
        }
        ++M;
        graph[1].push_back({index, base});
        base += curOps;
    }

    while (base < L) {
        ++M;
        graph[1].push_back({14, base});
        ++base;
    }
    cout << 14 << " " << M << endl;
    FOR(i, 1, 15) {
        for (pii x : graph[i]) {
            cout << i << " " << x.first << " " << x.second << endl;
            --M;
        }
    }
}
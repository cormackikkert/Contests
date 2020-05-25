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

vll dist; 
vll cost;

ll N, C;

ll best(vll dist, vll cost) {
    ll top = 0;
    ll cur = 0;
    ll pos = 0;
    F0R(i, N) {
        cur += pos - dist[i] + cost[i];
        pos = dist[i];
        // cout << i << " " << cur << endl;
        top = max(top, cur);
        
    }
    return top;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> C;

    dist.resize(N);
    cost.resize(N);

    F0R(i, N) {
        cin >> dist[i] >> cost[i];
    }

    ll top = best(dist, cost);

    reverse(cost.begin(), cost.end());
    reverse(dist.begin(), dist.end());
    F0R(i, N) dist[i] = C - dist[i];

    top = max(top, best(dist, cost));

    cout << top << endl;
}
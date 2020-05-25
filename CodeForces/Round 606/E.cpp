#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = 1LL << 60;
 
using vc = vector<char>;
using vi = vector<int>;

vector<vi> graph;
vector<bool> visited;

ll csize;
bool hitA;
bool hitB;

ll A;
ll B;

void dfs(int i) {
    ++csize;
    visited[i] = true;
    for (int n : graph[i]) {
        if (n == A) {hitA = true; continue;}
        if (n == B) {hitB = true; continue;}
        if (!visited[n]) dfs(n);
    }
}
void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    --a; --b;
    A = a;
    B = b;
    graph.clear(); graph.resize(n); 
    visited.clear(); visited.resize(n); 
    F0R(i, m) {
        ll u, v; cin >> u >> v;
        --u; --v;
        // if (u == a || u == b || v == a || v == b) continue;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }    
    ll total = (n * (n-1)) / 2;
    ll Atot = 0;
    ll Btot = 0;
    F0R(i, n) {
        if (i == a || i == b) continue;
        csize = 0;
        if (visited[i]) continue;
        hitA = false;
        hitB = false;
        dfs(i);
        if (hitA && hitB) continue;
        if (hitA) Atot += csize;
        if (hitB) Btot += csize;
    }
    cout << Atot * Btot << endl;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t;
    //F0R(i, t) solve();
    string s;
    F0R(i, 150000) s += "two";
    cout << "done"<< endl;
}
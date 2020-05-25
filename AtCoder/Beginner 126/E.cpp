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
using vb = vector<bool>;

int N, M;
vector<vi> graph; 
vb visited;

void dfs(int pos) {
    visited[pos] = true;
    for (int n : graph[pos]) {
        if (!visited[n]) dfs(n);
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    graph.resize(N);
    F0R(i, M) {
        int a, b, _; cin >> a >> b >> _;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    visited = vb (N);
    int components = 0;
    F0R(i, N) {
        if (!visited[i]) dfs(i), ++components;
    }

    cout << components << endl;
}
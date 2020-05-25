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
ll N, M;
vector<vi> graph; 
vi inDegree;
vi parent;
vb visited; 
void search(int cur, int par) {
    parent[cur] = par;
    visited[cur] = true;
    for (int n : graph[cur]) {
        --inDegree[n];
    }
    for (int n : graph[cur]) {
        if (!visited[n] && inDegree[n] == 0) search(n, cur);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    graph.resize(N);
    inDegree.resize(N);
    parent.resize(N);
    visited.resize(N);
    F0R(i, N-1+M) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        ++inDegree[b];
    }
    F0R(i, N) if (inDegree[i] == 0) {search(i, -1); break;}    
    F0R(i, N) cout << parent[i] + 1 << endl;
}
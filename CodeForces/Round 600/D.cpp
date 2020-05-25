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

int N, M; 
vector<vi> graph;
vector<bool> visited;

int curMax;
void dfs(int cur) {
    curMax = max(cur, curMax);
    visited[cur] = true;
    for (int n : graph[cur]) {
        if (!visited[n]) dfs(n);
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    graph.resize(N);
    visited.resize(N);
    F0R(i, M) {
        int a, b; cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int t = 0;
    F0R(i, N) {
        if (visited[i]) continue;
        curMax = i;
        dfs(i);
        FOR(j, i, curMax+1) {
            if (visited[j]) continue;
            ++t;
            dfs(j);
        }
    }
    cout << t << endl;
}
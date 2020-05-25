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
using state = pair<int, int>;

vector<vi> graph;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M; cin >> N >> M;
    graph.resize(N);

    vector<vb> visited (N, {false, false, false});
    vector<vi> dist (N, {-1, -1, -1});

    F0R(i, M) {
        int u, v; cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
    }

    int S, T; cin >> S >> T;
    --S; --T;

    queue<state> q;
    visited[S][0] = true;
    dist[S][0] = 0;
    q.push({S, 0});

    while (!q.empty()) {
        int pos = q.front().first;
        int par = q.front().second;
        q.pop();

        if (pos == T && par == 0) {
            cout << dist[pos][par] / 3 << endl; return 0;
        }

        for (int nPos : graph[pos]) {
            int nPar = (par + 1) % 3;
            if (visited[nPos][nPar]) continue;
            dist[nPos][nPar] = dist[pos][par] + 1;
            visited[nPos][nPar] = true;
            q.push({nPos, nPar});
        }
    }
    cout << -1 << endl;
}
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct BipartiteMatching {
	int L, R, p;  vi m, used, d; vvi adj; queue<int> q;
  bool bfs() {
    for (int v=0; v<R; v++) if (!used[v]) d[v] = p, q.push(v);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      if (d[v] != d[R]) for (int u : adj[v]) if (d[m[u]] < p)
        d[m[u]] = d[v] + 1, q.push(m[u]);
    }
    return d[R] >= p;
  }
	int dfs(int v) {
    if (v == R) return 1;
    for (int u : adj[v]) if (d[m[u]] == d[v] + 1 && dfs(m[u])) return m[u] = v, 1;
    d[v] = d[R];  return 0;
	}
	BipartiteMatching(int L, int R) : L(L), R(R), d(R+1), adj(R) { }
	void add_edge(int u, int v) { adj[v].push_back(u); }
	pair<int, vi> match() {
		int res = 0;  m.assign(L, R), used.assign(R+1, 0);
		for (p=0; bfs(); p = d[R]+1) for (int v=0; v<R; v++)
      if (!used[v] && dfs(v)) used[v] = 1, res++;
    replace(m.begin(), m.end(), R, -1); return {res, m};
	}
};


int main() {
  // Read input
  int N, M;
  cin >> N >> M;
  
  vector<string> malcolm(N), richard(M);
  string cur;
  
  for (auto& x : malcolm)
    cin >> x;
  for (auto& x : richard)
    cin >> x;
  cin >> cur;
  
  // Create Bipartite Graph where each player's cards
  // have edges between cards of the same colour or
  // numeric value.
  BipartiteMatching G(N, M + 1);
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (malcolm[i][0] == richard[j][0] || malcolm[i][1] == richard[j][1])
        G.add_edge(i, j);
    }
    if (malcolm[i][0] == cur[0] || malcolm[i][1] == cur[1])
      G.add_edge(i, M);
  }
  
  // Perform bipartite matching with and without the current
  // card on the table
  int ans = G.match().first;
  G.R--;
  int new_ans = G.match().first;
  
  // Malcolm wins if and only if the current card is contained
  // in every maximum matching of G
  if (new_ans < ans)
    cout << "Malcolm\n";
  else
    cout << "Richard\n";
}


#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct BipartiteMatching {
	int L, R, p;  vi m, vis;  vvi adj;
	int dfs(int v) {
		vis[v] = p;
		for (auto u : adj[v]) if (m[u] < 0 || (vis[m[u]] != p && dfs(m[u])))
			return m[u] = v, 1;
		return 0;
	}
	BipartiteMatching(int l, int r) : L(l), R(r), adj(r) { }
	void add_edge(int u, int v) { adj[v].push_back(u); }
	pair<int, vi> match() {
		int res = 0;  m.assign(L, -1), vis.assign(R, -1);
		for (p = 0; p < R; p++) res += dfs(p);
		return {res, m};
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


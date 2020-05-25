// O( n * m )

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct BipartiteMatching {
  int L, R, p;  vi m, vis;  vvi adj;
  int dfs(int v) {
    vis[v] = p;
    for (auto u : adj[v])
      if (m[u] < 0 || (vis[m[u]] != p && dfs(m[u])))
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

int main(){
  int m,r; cin >> m >> r;

  vector<string> M(m),R(r+1);
  for(int i=0;i<m;i++) cin >> M[i];
  for(int i=0;i<r;i++) cin >> R[i];
  cin >> R[r];

  BipartiteMatching G1(m,r+1), G2(m,r);
  
  for(int i=0;i<m;i++)
    for(int j=0;j<=r;j++)
      if(M[i][0] == R[j][0] || M[i][1] == R[j][1]){
	G1.add_edge(i,j);
	if(j != r) G2.add_edge(i,j);
      }
  
  int match1 = G1.match().first;
  int match2 = G2.match().first;

  cout << (match1 == match2 ? "Richard" : "Malcolm") << endl;
}

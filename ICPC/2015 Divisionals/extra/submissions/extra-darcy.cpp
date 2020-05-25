#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

// Finds bridges and 2-edge-connected components
struct Biconnectivity {
  struct edge {
    int u, v, vcomp;  bool used, bridge;
    edge(int a, int b) : u(a), v(b) { }
    int other(int w) { return w == u ? v : u; }
  };
  int n, m, n_bcomps, dfs_count;
  vi dfs_num, dfs_low, bcur, bcomp; vvi adj; vector<edge> edges;
  void make_bcomp(int v) {
    int u = -1; n_bcomps++;
    while (u != v) { u = bcur.back(); bcur.pop_back(); bcomp[u] = n_bcomps - 1; }
  }
  void dfs(int u) {
    dfs_low[u] = dfs_num[u] = dfs_count++;
    for (auto i : adj[u]) if (!edges[i].used) {
      auto& e = edges[i]; int v = e.other(u);  e.used = true;
      if (dfs_num[v] == -1) {
        bcur.push_back(v), dfs(v);
        if (dfs_low[v] > dfs_num[u]) { e.bridge = true; make_bcomp(v); }
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      } else {
        dfs_low[u] = min(dfs_low[u], dfs_num[v]);
      }
    }
  }
  Biconnectivity(int n) : n(n), m(0), adj(n) { }
  edge& get_edge(int i) { return edges[i]; }
  int add_edge(int u, int v) {
    adj[u].push_back(m), adj[v].push_back(m), edges.emplace_back(u, v);
    return m++;
  }
  void find_components() {
    dfs_num.assign(n, -1); dfs_low.assign(n, 0); dfs_count = 0;
    bcur.clear(); bcomp.assign(n, -1); n_bcomps = 0;
    for (auto& e : edges) e.used = false, e.bridge = false;
    for (int v = 0; v < n; v++) if (dfs_num[v] == -1) {
      bcur = {v}; dfs(v); make_bcomp(v);
    }
  }
};

int main(){
  int n; cin >> n;

  Biconnectivity G(n);
  
  for(int u=0;u<n;u++){
    int d; cin >> d;
    for(int j=0;j<d;j++){
      int v; cin >> v;
      G.add_edge(u,v);
    }
  }

  G.find_components();

  vector<set<int> > adj(G.n_bcomps);
  for( const auto& e : G.edges){
    int U = G.bcomp[e.u], V = G.bcomp[e.v];
    if(U != V){
      adj[U].insert(V);
      adj[V].insert(U);
    }
  }

  int leaves = 0;
  for(int i=0;i<G.n_bcomps;i++)
    if(adj[i].size() == 1)
      leaves++;
  if(leaves == 0) leaves++;
  cout << leaves-1 << endl;
}

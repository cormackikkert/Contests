#include <bits/stdc++.h>

using namespace std;

struct BridgesAndArtics {
	vector<int> time, es, children;
	vector<vector<int>> adj; // no duplicate edges +  undirected graphs only
	set<int> artics; set<pair<int, int>> bridges;
	int t, root;
	int dfs(int at, int p) { // returns earliest node seen by children
		if (es[at] != -1) return es[at]; // don't recompute earliest.
		time[at] = t++; es[at] = at; children[at] = 0; // init arrays
		for (int c : adj[at]) if (c != p) { // iterate through non-parent links
			if (time[c] == -1) ++children[at];
			int e = time[c]==-1 ? dfs(c, at) : c; // get child earliest
			if (time[e] < time[es[at]]) es[at] = e; // update earliest seen
		}
		if (at != root) { // find those tasty articulations
			if (es[at] == at) {
				if (p != root) artics.insert(p);
				if (children[at] != 0) artics.insert(at);
				bridges.insert(make_pair(p, at));
				bridges.insert(make_pair(at, p));
			} else if (es[at] == p && p != root) artics.insert(p);
		}
		return es[at];
	}
	void compute_sets(const vector<vector<int>> &a) { // computes artics and bridges
		const int N = a.size();
		adj = a; t = 0; root = 0;
		time.assign(N, -1); es = time; children = time;
		artics.clear(); bridges.clear();
		dfs(root, root); // explore dfs tree and fill tables
		if (children[root] >= 2) artics.insert(root); // check root
	}
};

BridgesAndArtics ba;

vector<vector<int>> adj;

vector<int> vis;

int leaves = 0;

int dfs(int at) {
	vis[at] = 1;
	int cnt = 0;
	for (int c : adj[at]) if (!vis[c]) {
		if (ba.bridges.count(make_pair(at, c))) {
			++cnt;
			if (!dfs(c))
				++leaves;
		} else {
			cnt += dfs(c);
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int S;
	cin >> S;

	adj.resize(S);

	for (int i = 0; i < S; ++i) {
		int l;
		cin >> l;
		for (int j = 0; j < l; ++j) {
			int s;
			cin >> s;

			adj[i].push_back(s);
			adj[s].push_back(i);
		}
	}

	ba.compute_sets(adj);

	if (!ba.bridges.size()) {
		cout << 0 << endl;
		return 0;
	}

	vis.assign(S, 0);

	if (dfs(0) == 1)
		++leaves;

	cout << leaves-1 << endl;
}

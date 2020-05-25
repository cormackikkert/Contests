#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.first,", ",x.second,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void print() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void print(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); print(ts...); 
	}
}

using namespace output;

int BIG = 100000;

using pii = pair<int, int>;
pii furthest(vector<vector<pii>> graph, int parent, int current) {
	int furNode = current;
	int furDist = 0;

	for (pii edge : graph[current]) {
		int node = edge.first;
		int len = edge.second;

		if (parent == node) continue; 

		pii newDist = furthest(graph, current, node);

		if (newDist.second + len > furDist) {
			furDist = newDist.second + len;
			furNode = newDist.first;
		}
	}

	return pii {furNode, furDist};
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, H; cin >> N >> H;
	set<int> edges;
	map<int, int> weights;
	for (int i = 0; i < N; ++i) {
		int node, weight; cin >> node >> weight;
		edges.insert(node);
		weights[node] = weight;
	}

	// print("CALC");
	vector<vector<pii>> graph (BIG);
	vector<bool> discovered (BIG);
	for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
		int node = *it;
		
		int len = weights[node];
		if (!discovered[node]) {
			int temp = node;
			while (temp < pow(2, H - 1)) {temp *= 2; ++len;}
		}

		// print(node, (int) discovered[node], len);
		discovered[node] = true;
		node /= 2;
		while (edges.find(node) == edges.end() && node != 1) {
			if (!discovered[node / 2]) ++len;
			discovered[node] = true;
			node = node / 2;
		}

		print(*it, node, len);
		discovered[node] = true;

		graph[node].push_back(pii {*it, len});
		graph[*it].push_back(pii {node, len});
	}
	// print("---");
	pair<int, int> res = furthest(graph, -1, 1);
	// print(res);
	print(furthest(graph, -1, res.first).second);
}
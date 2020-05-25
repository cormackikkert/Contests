#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;

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
		pr("{",x.f,", ",x.s,"}"); 
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


const int INF = 1000000000;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int H, W; cin >> H >> W;
	vector<vi> grid (H, vi (W));
	F0R(i, H) {
		F0R(j, W) {
			char c; cin >> c;
			grid[i][j] = c == '#';
		}
	}
	
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
	vector<vi> dist (H, vi (W, INF));
	dist[0][0] = grid[0][0];
	q.push({dist[0][0], {0, 0}});
	while (!q.empty()) {
		pii v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (dist[v.second][v.first] != d_v) continue;

		if (v.first + 1 < W) {
			int d = !grid[v.second][v.first] && grid[v.second][v.first + 1];
			if (d + d_v < dist[v.second][v.first + 1]) {
				dist[v.second][v.first + 1] = d + d_v;
				q.push({d + d_v, {v.first + 1, v.second}});
			}
		}

		if (v.second + 1 < H) {
			int d = !grid[v.second][v.first] && grid[v.second + 1][v.first];
			if (d + d_v < dist[v.second + 1][v.first]) {
				dist[v.second + 1][v.first] = d + d_v;
				q.push({d + d_v, {v.first, v.second + 1}});
			}
		}
	}
	print(dist[H-1][W-1]);
}
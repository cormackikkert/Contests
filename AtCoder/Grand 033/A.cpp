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

vector<pii> deltas = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int H, W; cin >> H >> W;
	vector<string> arr (H);
	F0R(i, H) cin >> arr[i];
	vector<vector<bool>> seen (H, vector<bool> (W));
	vector<vector<int>> dist (H, vector<int> (W));

	queue<pii> q; 
	F0R(i, H) F0R(j, W) if (arr[i][j] == '#') {
		q.push({j, i});
		seen[i][j] = true;
	}
	
	while (!q.empty()) {
		pii pos = q.front(); q.pop();
		
		for (pii d : deltas) {
			int nx = pos.first + d.first;
			int ny = pos.second + d.second;
			if (0 <= nx && nx < W && 0 <= ny && ny < H && !seen[ny][nx]) {
				seen[ny][nx] = true;
				dist[ny][nx] = 1 + dist[pos.second][pos.first];
				q.push({nx, ny});
			}
		}
	}

	int best = 0;
	F0R(i, H) F0R(j, W) best = max(best, dist[i][j]);
	print(best);	
}
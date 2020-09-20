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

vi DX = {0, 0, -1, 1};
vi DY = {-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int H, W; cin >> H >> W;
	int CH, CW; cin >> CH >> CW; --CH; --CW;
	int DH, DW; cin >> DH >> DW; --DH; --DW;
	vector<vector<bool>> grid (H, vector<bool> (W));
	vector<vector<int>> dist (H, vector<int> (W, 1e9));

	F0R(i, H) F0R(j, W) {
		char c; cin >> c;
		grid[i][j] = c == '#';
	}
	dist[CH][CW] = 0;
	deque<pair<int, int>> q;
	q.push_front({CH, CW});
	while (!q.empty()) {
		pair<int, int> pos = q.front();
		int ph = pos.first;
		int pw = pos.second;
		q.pop_front();
		F0R(i, 4) {
			int nh = ph + DX[i];
			int nw = pw + DY[i];
			if (0 <= nh && nh < H && 0 <= nw && nw < W && !grid[nh][nw]) {
				if (dist[ph][pw] < dist[nh][nw]) {
					dist[nh][nw] = dist[ph][pw];
					q.push_front({nh, nw});
				}
			}
		}
		for (int nh = ph - 2; nh <= ph + 2; ++nh) {
			for (int nw = pw - 2; nw <= pw + 2; ++nw) {
				if (0 <= nh && nh < H && 0 <= nw && nw < W && !grid[nh][nw]) {
					if (dist[ph][pw] + 1 < dist[nh][nw]) {
						dist[nh][nw] = dist[ph][pw] + 1;
						q.push_back({nh, nw});
					}
				}
			}
		}
	}
	print((dist[DH][DW] == (int) 1e9) ? -1 : dist[DH][DW]);
}
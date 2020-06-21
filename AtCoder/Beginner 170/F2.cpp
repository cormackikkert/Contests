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

int inf = 1e9;

vi DX = {-1, 1, 0, 0};
vi DY = {0, 0, -1, 1};

int opp(int d) {
	if (d == 0) return 1;
	if (d == 1) return 0;
	if (d == 2) return 3;
	if (d == 3) return 2;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int H, W, K; cin >> H >> W >> K;
	int X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2; --X1; --Y1; --X2; --Y2;
	swap(X1, Y1);
	swap(X2, Y2);

	vector<vector<bool>> grid (H, vector<bool> (W));
	F0R(i, H) {
		F0R(j, W) {
			char c; cin >> c;
			grid[i][j] = c == '@';
		}
	}

	vector<vector<int>> dist (H, vector<int> (W, inf));
	using state = tuple<int, int, int>;
	deque<state> q;
	dist[Y1][X1] = 0;	
	q.push_back(make_tuple(X1, Y1, 0));

	while (!q.empty()) {
		state p = q.front();
		q.pop_front();

		int x = get<0>(p);
		int y = get<1>(p);
		int s = get<2>(p);

		F0R(d, 4) if ((s & (1 << d)) == 0) {
			for (int l = 0; l <= K; ++l) {
				int nx = x + DX[d] * l;
				int ny = y + DY[d] * l;
				if (0 > nx || nx >= W || 0 > ny || ny >= H || grid[ny][nx]) break;
				if (dist[y][x] + 1 < dist[ny][nx]) {
					dist[ny][nx] = dist[y][x] + 1;
					
					int skip = 0;
					if (l != K) {
						skip |= (1 << d);
						skip |= (1 << opp(d));
					} else {
						skip |= (1 << opp(d));
					}
					q.push_back(make_tuple(nx, ny, skip));
				}
			}
		}
	}

	print((dist[Y2][X2] < inf) ? dist[Y2][X2] : -1);
}
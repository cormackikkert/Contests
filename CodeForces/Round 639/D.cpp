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
int N, M;
vector<vector<bool>> seen;
vector<vector<bool>> grid;

vi DX = {-1, 1, 0, 0};
vi DY = {0, 0, -1, 1};

vi seeny;
vi seenx;

void dfs(int x, int y) {
	seeny[y] = true;
	seenx[x] = true;
	seen[y][x] = true;
	F0R(i, 4) {
		int nx = x + DX[i];
		int ny = y + DY[i];
		if (0 <= nx && nx < M && 0 <= ny && ny < N && !seen[ny][nx] && grid[ny][nx]) dfs(nx, ny);
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	 cin >> N >> M;
	grid = vector<vector<bool>> (N, vector<bool> (M));
	seen = vector<vector<bool>> (N, vector<bool> (M));
	

	seeny.resize(N);
	seenx.resize(M);

	F0R(i, N) F0R(j, M) {
		char c; cin >> c;
		grid[i][j] = c == '#';
	}

	vi rowEmpty;
	F0R(i, N) {
		int state = 0;
		F0R(j, M) {
			if (!grid[i][j]) {
				if (state == 1) ++state;
			} else {
				if (state == 0) ++state;
				if (state == 2) {
					print(-1);
					return 0;
				}
			}
		}
		if (state == 0) rowEmpty.push_back(i);
	}

	vi colEmpty;
	F0R(j, M) {
		int state = 0;
		F0R(i, N) {
			if (!grid[i][j]) {
				if (state == 1) ++state;
			} else {
				if (state == 0) ++state;
				if (state == 2) {
					print(-1);
					return 0;
				}
			}
		}
		if (state == 0) colEmpty.push_back(j);
	}

	int cnt = 0;
	F0R(y, N) F0R(x, M) if (!seen[y][x] && grid[y][x]) {
		dfs(x, y);
		++cnt;
	}

	for (int c : colEmpty) for (int r : rowEmpty) {
		seeny[r] = true;
		seenx[c] = true;
	}
	bool works = true;
	F0R(i, N) works &= seeny[i];
	F0R(i, M) works &= seenx[i];
	
	print(works ? cnt : -1);
}
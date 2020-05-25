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

vector<vi> bg;
vector<vi> wg;

vector<vi> csb;
vector<vi> csw;

int N, K;

int getCount(int x, int y, bool col) {
	if (y + K < 0 || x + K < 0 || x >= 2 * K || y >= 2 * K) return 0;

	int nx2 = min(2 * K, x + K);
	int nx1 = max(0, x);
	int ny2 = min(2 * K, y + K);
	int ny1 = max(0, y);

	if (col) {
		return csb[ny2][nx2] - csb[ny2][nx1] - csb[ny1][nx2] + csb[ny1][nx1];
	} else {
		return csw[ny2][nx2] - csw[ny2][nx1] - csw[ny1][nx2] + csw[ny1][nx1];
	}
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;

	bg = vector<vi> (2 * K, vi (2 * K));
	wg = vector<vi> (2 * K, vi (2 * K));
	csb = vector<vi> (2 * K + 2, vi (2 * K + 2));
	csw = vector<vi> (2 * K + 2, vi (2 * K + 2));

	for (int i = 0; i < N; ++i) { 
		int x, y; char c;
		cin >> x >> y >> c;
		x %= 2 * K;
		y %= 2 * K;
		if (c == 'W') 
			wg[y][x]++;
		else
			bg[y][x]++;
	}

	for (int i = 0; i <= 2 * K; ++i) {
		for (int j = 0; j <= 2 * K; ++j) {
			if (i < 2 * K && j < 2 * K) csb[i+1][j+1] += bg[i][j];
			csb[i+1][j+1] += csb[i][j+1];
			csb[i+1][j+1] += csb[i+1][j];
			csb[i+1][j+1] -= csb[i][j];

			if (i < 2 * K && j < 2 * K) csw[i+1][j+1] += wg[i][j];
			csw[i+1][j+1] += csw[i][j+1];
			csw[i+1][j+1] += csw[i+1][j];
			csw[i+1][j+1] -= csw[i][j];
		}
	}

	int best = 0;

	for (int x = 0; x < K; ++x) {
		for (int y = 0; y < K; ++y) {
			for (bool col : {false, true}) {
				
				int cur = 0;
				for (int dx : {-1, 0, 1}) {
					for (int dy : {-1, 0, 1}) {
						bool c = col ^ ((dx + dy + 2) % 2 == 0);
						cur += getCount(x + dx * K, y + dy * K, c);
					}
				}

				best = max(best, cur);
			}
		}
	}
	
	print(best);
}
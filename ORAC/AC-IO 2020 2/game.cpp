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

const int SIZE = 10;
bool calc [SIZE+1][SIZE+1][SIZE+1][SIZE+1];

using state = tuple<int, int, int, int>;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	calc[0][0][0][0] = true;

	FOR(s, 1, 4 * SIZE + 1) {
		F0R(a, min(SIZE, s) + 1) {
			F0R(b, min(SIZE, s - a) + 1) {
				F0R(c, min(SIZE, s - a - b) + 1) {
					int d = s - a - b - c;
					if (d > SIZE) continue;
					
					bool allWinning = true;

					F0R(i, a) allWinning &= calc[i][b][c][d];
					F0R(i, b) allWinning &= calc[a][i][c][d];
					F0R(i, c) allWinning &= calc[a][b][i][d];
					F0R(i, d) allWinning &= calc[a][b][c][i];

					calc[a][b][c][d] = !allWinning;

					if (a < b && b < c && c < d && a != b && b != c && c != d)
						print(a, b, c, d, a^b^c^d, calc[a][b][c][d]);
				}
			}
		}
	}
	// cout << "Calculation complete" << endl;
	// while (true) {
	// 	int a, b, c, d; cin >> a >> b >> c >> d;
	// 	cout << "Is winning? " << calc[a][b][c][d] << endl;
	// }
}
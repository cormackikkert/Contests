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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N; cin >> N;
	vll SS (N);
	vll TS (N);
	vll US (N);
	vll VS (N);
	F0R(i, N) cin >> SS[i];
	F0R(i, N) cin >> TS[i];
	F0R(i, N) cin >> US[i];
	F0R(i, N) cin >> VS[i];
	vector<vll> arr (N, vll (N));
	vector<vll> fix (N, vll (N));

	bool fail = false;

	vector<pair<int, int>> C0;
	vector<pair<int, int>> C1;
	vector<pair<int, int>> R0;
	vector<pair<int, int>> R1;

	// rows
	F0R(i, N) {
		if (S[i] == 0) {
			// AND case
			for (int k = 0; k < 64; ++k) {
				if (US[i] & (1 << k)) {
					// everything 1
					F0R(j, N) {
						if ((fix[i][j] & (1 << k)) && ((arr[i][j] & (1 << k)) == 0)) fail = true;
						arr[i][j] |= (1 << k);
						fix[i][j] |= (1 << k);
					}
				} else {
					R0.push_back({i, k});
				}
			}
		} else {
			// OR case
			for (int k = 0; k < 64; ++k) {
				if ((US[i] & (1 << k)) == 0) {
					/// everything 0
					F0R(j, N) {
						if ((fix[i][j] & (1 << k)) && ((arr[i][j] & (1 << k)) != 0)) fail = true;
						fix[i][j] |= (1 << k);
					}
				} else {
					// at leat a 1
					R1.push_back({i, k});
					
				}
			}
		}
	}

	// cols
	F0R(j, N) {
		if (T[j] == 0) {
			// AND case
			for (int k = 0; k < 64; ++k) {
				if (VS[j] & (1 << k)) {
					// everything 1
					F0R(i, N) {
						if ((fix[i][j] & (1 << k)) && ((arr[i][j] & (1 << k)) == 0)) fail = true;
						arr[i][j] |= (1 << k);
						fix[i][j] |= (1 << k);
					}
				} else {
					C0.push_back({j, k});
				}
			}
		} else {
			// OR case
			for (int k = 0; k < 64; ++k) {
				if ((VS[j] & (1 << k)) == 0) {
					/// everything 0
					F0R(i, N) {
						if ((fix[i][j] & (1LL << k)) && ((arr[i][j] & (1LL << k)) != 0)) fail = true;
						fix[i][j] |= (1LL << k);
					}
				} else {
					// at leat a 1
					C1.push_back({j, k});
				}
			}
		}
	}

	if (fail) {
		print(-1);
	} else if ((C0.size() > 0) && (R0.size() > 0)) {
		F0R(i, N) {
			fix[i][C0[0].first] |= (1LL << C0[0].second); 
		}
		F0R(j, N) {
			fix[R0[0].first][i] |= (1LL << R0[0].second);
		}
		F0R(pair<int, int> x : C1) {
			F0R(i, N) {
				if ((fix[i][x.first] & (1LL << x.second)) != 0) continue;
				arr[i][x.first] |= (1LL << x.second);
			}
		}
		F0R(pair<int, int> x : R1) {
			F0R(j, N) {
				if ((fix[x.first][j] & (1LL << x.second)) != 0) continue;
				arr[x.first][j] |= (1LL << x.second);
			}
		}
	} else if ((C1.size() > 0) && (R1.size() > 0)) {

	} else if (C1. {
		print(-1);
	}
}
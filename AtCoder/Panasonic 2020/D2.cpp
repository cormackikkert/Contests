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
	int N; cin >> N;

	set<string> rec;
	for (int a = 0; a < (1 << N); ++a) {
		for (int b = 0; b < a; ++b) {
			for (int c = 0; c < b; ++c) {
				for (int d = 0; d < c; ++d) {
					for (int e = 0; e < d; ++e) {
						for (int f = 0; f < e; ++f) {
							for (int g = 0; g < f; ++g) {
								for (int h = 0; h < g; ++h) {
									for (int i = 0; i < h; ++i) {
										for (int j = 0; j < i; ++j) {
											if (((a + b + c + d + e + f + g + h + i + j) == ((1 << N) - 1)) &&
												(a | b | c | d | e | f | g | h | i | j) == ((1 << N) - 1)) {
												vi arr (N);
												arr.push_back(a);
												arr.push_back(b);
												arr.push_back(c);
												arr.push_back(d);
												arr.push_back(e);
												arr.push_back(f);
												arr.push_back(g);
												arr.push_back(h);
												arr.push_back(i);
												arr.push_back(j);
												sort(arr.begin(), arr.end());
												reverse(arr.begin(), arr.end());
												vector<char> res (N);
												bool fail = false;
												char c = 'a' - 1;
												for (int mask : arr) if (mask) {
													++c;
													F0R(x, N) {
														if (mask & (1 << x)) {
															if (res[N-x-1] != 0) fail = true;
															res[N-x-1] = c;	
														}
													}
												}
												
												if (!fail) {
													string final (res.begin(), res.end());
													rec.insert(final);
												}
											}
										}
									}
								}
							}
						}
					}
				}	
			}
		}
	}
	for (string x : rec) {
		print(x);
	}
}
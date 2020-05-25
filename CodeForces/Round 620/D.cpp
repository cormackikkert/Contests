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

string getMin(int N, string S) {
	vi ans (N);

	int cur = 1;
	for (int hi = N - 2; hi >= 0; --hi) {
		if (S[hi] == '>') {
			if (hi == 0 || S[hi-1] == '>') {
				if (ans[hi + 1] == 0) {
					ans[hi + 1] = cur; ++cur;
				}
				ans[hi] = cur; ++cur;
			} else if (hi == N - 2) {
				ans[hi + 1] = cur; ++cur;
			}
			continue;
		}
		int lo = hi;
		while (lo > 0 && S[lo - 1] == '<') --lo;
		
		for (int ind = lo; ind <= hi + 1; ++ind) {
			ans[ind] = cur;
			++cur;
		}

		hi = lo;
	}

	string x;
	for (int a : ans) {
		x += to_string(a) + " ";
	}
	return x;
}

string getMax(int N, string S) {
	vi ans (N);
	int cur = 1;

	int ind = N - 1;
	while (S[ind - 1] == '>') {
		ans[ind] = cur; ++cur;
		--ind;
	}

	for (int i = 0; i < N - 1; ++i) {
		if (ans[i] != 0) continue;
		if (S[i] == '<') {
			ans[i] = cur; ++cur;
		}
	}

	cur = N;
	for (int i = 0; i < N; ++i) {
		if (ans[i] == 0) {
			ans[i] = cur; --cur;
		}
	}

	string x;
	for (int a : ans) {
		x += to_string(a) + " ";
	}
	return x;
}
void solve() {
	int N; cin >> N;
	string S; cin >> S;

	print(getMin(N, S));
	print(getMax(N, S));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	F0R(i, T) solve();
}
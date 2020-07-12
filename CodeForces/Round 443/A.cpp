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

int N;
int process(vector<pii>& data, int number) {
	F0R(i, N) {
		if (data[i].first == 0) number &= data[i].second;
		if (data[i].first == 1) number |= data[i].second;
		if (data[i].first == 2) number ^= data[i].second;
	}
	return number;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	// 0 -> &
	// 1 -> | 
	// 2 -> ^
	vector<pii> data (N);
	F0R(i, N) {
		char c; cin >> c;
		int x; cin >> x;
		if (c == '&') data[i].first = 0;
		if (c == '|') data[i].first = 1;
		if (c == '^') data[i].first = 2;
		data[i].second = x;
	}

	int band = 0;
	int bor = 0;
	int bxor = 0;
	F0R(i, 10) {
		int r0 = process(data, 0) & (1 << i);
		int r1 = process(data, 1 << i) & (1 << i);
		if (r0 == 0 && r1 == 0) {
			// nothing
		} else if (r0 == 0 && r1 > 0) {
			band |= 1 << i;
		} else if (r0 > 0 && r1 == 0) {
			band |= 1 << i;
			bxor |= 1 << i;
		} else {
			band |= 1 << i;
			bor |= 1 << i;
		}
	}
	print(3);
	print("&", band);
	print("|", bor);
	print("^", bxor);
}
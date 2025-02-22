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
using pll = pair<ll, ll>;

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
		pr("{",x.first,", ",x.second,"}"); 
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
	vector<pll> data (N);
	F0R(i, N) {
		string S; cin >> S;
		ll total = 0;
		ll deep = 0;
		for (char c : S) {
			if (c == '(') ++total;
			if (c == ')') --total;
			deep = min(deep, total);
		}
		data[i] = {deep, total};
	}

	ll sum = 0;
	for (pll d : data) sum += d.second;

	if (sum != 0) {
		print("No");
		return 0;
	}

	sort(data.begin(), data.end(), [] (const auto& lhs, const auto& rhs) {
		if ((lhs.second >= 0) ^ (rhs.second >= 0)) {
			return lhs.second >= 0;
		} else if (lhs.second >= 0) {
			return lhs.first > rhs.first;
		} else {
			return lhs.second - lhs.first > rhs.second - rhs.first;
		}
	});

	ll total = 0;
	for (pll d : data) {
		if (total + d.first < 0) {
			print("No");
			return 0;
		}
		total += d.second;
	}
	print("Yes");
}
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
vi los;
vi his;

bool possible(int x) {
	int below = 0;
	int above = 0;
	int both = 0;
	F0R(i, N) {
		if (los[i] <= x && x <= his[i]) ++both;
		else if (his[i] < x) ++below;
		else ++above;
	}
	return (below < (N/2)) && (above <= (N/2)); 
}

int bs1() {
	int lo = 0;
	int hi = 1e9;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;

		int count = 0;
		F0R(i, N) if (los[i] <= mid) ++count;
		
		if (count >= N-(N/2)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int bs2() {
	int lo = 0;
	int hi = 1e9;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;

		int count = 0;
		F0R(i, N) if (his[i] >= mid) ++count;
		
		if (count > (N/2)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return lo;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> N;
	los.resize(N);
	his.resize(N);
	
	F0R(i, N) {
		cin >> los[i];
		cin >> his[i];
	}

	print(bs1(), bs2());
	
}
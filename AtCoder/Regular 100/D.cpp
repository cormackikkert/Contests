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
	vi arr (N); 
	F0R(i, N) cin >> arr[i];

	ll AS, BS, CS, DS;
	int D1 = 0;
	int D2 = 1;
	int D3 = 2;

	AS = arr[D1];
	FOR(i, 0, D1 + 1)      AS += arr[i];
	FOR(i, D1 + 1, D2 + 1) BS += arr[i];
	FOR(i, D2 + 1, D3 + 1) CS += arr[i];
	FOR(i, D3 + 1, N)      DS += arr[i];

	ll best = max(max(AS, BS), max(CS, DS)) - min(min(AS, BS), min(CS, DS));

	while (true) {
		while (abs((AS + arr[D1 + 1]) - (BS - arr[D1+1]) < abs(AS - BS)) {
			++D1;
			AS += arr[D1];
			BS -= arr[D1];
		}

		while (abs((CS + arr[D3 + 1]) - (DS - arr[D3 + 1])) < abs(CS - DS)) {
			++D3;
			CS += arr[]
		}
	}

}
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
	vector<pii> arr (N);

	vi s1 (N);
	vi e1 (N);
	vi s2 (N);
	vi e2 (N);
	vi s3 (N);
	vi e3 (N);
	vi s4 (N);
	vi e4 (N);
	F0R(i, N) {
		int a, b; cin >> a >> b; --a; --b;
		s1[i] = a + b;
		e1[i] = -a -b;
		s2[i] = a - b;
		e2[i] = b - a;
		s3[i] = -a + b;
		e3[i] = a - b;
		s4[i] = -a -b;
		e4[i] = a + b;
	}
	sort(s1.rbegin(), s1.rend());
	sort(s2.rbegin(), s2.rend());
	sort(s3.rbegin(), s3.rend());
	sort(s4.rbegin(), s4.rend());
	sort(e1.rbegin(), e1.rend());
	sort(e2.rbegin(), e2.rend());
	sort(e3.rbegin(), e3.rend());
	sort(e4.rbegin(), e4.rend());

	int hi = 0;
	hi = max(hi, s1[0] + e1[0]);
	hi = max(hi, s2[0] + e2[0]);
	hi = max(hi, s3[0] + e3[0]);
	hi = max(hi, s4[0] + e4[0]);
	print(hi);
	}
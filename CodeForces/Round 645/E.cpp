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
	ll B = (N + 1) / 2;
	ll A = N - B;

	vll arr (B);
	F0R(i, B) cin >> arr[i];
	ll X; cin >> X;
	
	if (X > 0) {
		ll sum = X * A;
		for (ll x : arr) sum += x;
		print((sum > 0) ? N : -1);
	} else {
		ll cs = X * A;
		ll all = 0;
		ll ans = -1;
		bool inUse = false;
		for (ll i = B - 1; i >= 0; --i) {
			cs -= X;
			cs += arr[i]; all += arr[i];
			if (cs <= 0) inUse = false;
			if (!inUse && all + X * A > 0) {
				ans = N - i;
				cs = all + X * A;
				inUse = true;
			}
		}
		if (inUse) {
			print(ans);
		} else {
			print(-1);
		}
	}
}
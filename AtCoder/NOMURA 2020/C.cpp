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
	vll arr (N + 1);
	F0R(i, N + 1) cin >> arr[i];

	if (N == 0 && arr[0] == 1) {
		print(1); return 0;
	}
	vll free (N+1);
	free[0] = 2;
	
	vll nodes (N+1);
	nodes[0] = 1;
	FOR(i, 1, N+1) {
		if (nodes[i-1] > (1LL<<50)) {
			nodes[i] = nodes[i-1];
		} else {
			nodes[i] = 2 * (nodes[i-1] - arr[i-1]);
			if (nodes[i] < arr[i]) {
				print(-1);
				return 0;
			}
		}
	}

	ll cur = 0;
	ll ans = 0;
	F0R(i, N+1) {
		ll X = arr[i];
		while (X > 0 && X >= free[cur]) {
			if (cur >= i) {
				print(-1);
				return 0;
			}
			ll remove = free[cur];
			free[cur] = 0;
			X -= remove;
			ans += remove * (i - cur);
			++cur;
			free[cur] = nodes[cur] - arr[cur];
		}
		if (X > 0) {
			if (cur >= i) {
				print(-1);
				return 0;
			}
			ans += X * (i - cur);
			free[cur] -= X;
		}
	}
	print(ans + 1);
}

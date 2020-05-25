#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define f first
#define s second

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

ll N, C; 

ll solve(vector<pair<ll, ll>> arr) {
	stack<pair<ll, ll>> mem;
	ll total = 0;
	ll dist = 0;
	mem.push({-1, 0});

	F0R(i, N) {
		total += arr[i].f - (arr[i].s - dist);
		dist = arr[i].s;
		if (total > mem.top().s) {
			mem.push({i, total});
		}
	}

	ll best = mem.top().s;

	total = 0;
	dist = 0;
	R0F(i, N) {
		total += arr[i].f - ((C - arr[i].s) - dist);
		dist = (C - arr[i].s);
		while (!mem.empty() && mem.top().f >= i) mem.pop();

		if (!mem.empty()) {
			// print(i, arr[i].s, total, mem.top(), dist, total + max(mem.top().s - dist, 0LL));
			best = max(best, total + max(mem.top().s - dist, 0LL));
		} else {
			// print(i, arr[i].s, total, "N");
			best = max(best, total);
		}
	}
	return best;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N >> C;
	vector<pair<ll, ll>> arr;
	F0R(i, N) {
		ll a, b; cin >> a >> b;
		arr.push_back(make_pair(b, a));
	}

	ll best = solve(arr);	

	F0R(i, N) arr[i].s = C - arr[i].s;

	reverse(arr.begin(), arr.end());

	best = max(best, solve(arr));
	print(best);
}
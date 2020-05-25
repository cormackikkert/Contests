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

ll MOD = 1e9 + 7;
const int MAXN = 2 * 1e5 + 10;
int N; 
vll fact (MAXN);
vll invfact (MAXN);
vll inv (MAXN);

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        res %= MOD;
        a = a * a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}

ll inverse(ll n) {
    return binpow(n, MOD-2);
}

ll choose(ll n, ll k) {
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

ll combine(vll nums) {
	ll sum = 0;
	for (ll s : nums) sum += s;
	ll ans = fact[sum];
	for (ll s : nums) ans *= invfact[s], ans %= MOD;
	return ans;
}

vector<vi> graph;
vector<pll> dp;
vector<ll> res;

// (size, ways)
pll dfs(int cur, int par) {
	print(cur);
	int pos = 0;
	vll childs;
	ll size = 0;
	ll ans = 1;
	for (int n : graph[cur]) if (n != par) {
		pll moves = dfs(n, cur);
		size += moves.first; 
		childs.push_back(moves.first);
		ans *= moves.second; ans %= MOD;
	}
	dp[cur] = {1 + size, ans * combine(childs) % MOD}; 
	return {1 + size, ans * combine(childs) % MOD};
}

void solve(int cur, int par, pll comb) {
	// pll (size, ways)
	// calc score

	res[cur] = dp[cur].second * comb.second * combine({dp[cur].first, comb.first});

	vll childs;
	ll ans = 1;
	ll size = 1;
	for (int n : graph[cur]) if (n != par) {
		childs.push_back(dp[n].first);
		size += dp[n].first;
		ans *= dp[n].second; ans %= MOD;
	}
	int i = 0;
	for (int n : graph[cur]) if (n != par) {
		ll old = childs[i];
		childs[i] = 0;
		solve(n, cur, {size, ans * combine(childs) % MOD});
		childs[i] = old;
		i++;
	}
}
int main() {
    fact[0] = 1;
    FOR(i, 1, MAXN) fact[i] = fact[i-1] * i % MOD;

    inv[1] = 1;
    FOR(i, 2, MAXN) inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;

    invfact[0] = 1;
    FOR(i, 1, MAXN) invfact[i] = invfact[i-1] * inv[i] % MOD;

	cin >> N;
	graph.resize(N);
	dp.resize(N);
	res.resize(N);
	F0R(i, N-1) {
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(0, -1);
	solve(0, -1, {0, 1});
	print(res);
}
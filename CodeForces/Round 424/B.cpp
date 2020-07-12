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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vi orig (N);
	vi arr;
	
	set<int> removedup; 
	F0R(i, N) {
		int x; cin >> x;
		removedup.insert(x);
		orig[i] = x;
	}

	for (int x : removedup) arr.push_back(x);
	
	vi narr (N);
	F0R(i, N) {
		narr[i] = lower_bound(arr.begin(), arr.end(), orig[i]) - arr.begin();
	}
	
	map<int, int> occ;
	for (int x : narr) occ[x]++;

	// {cur, {start, size}}
	set<pair<int, pii>> data; data.insert({narr[0], {narr[0], 1}});
	occ[narr[0]]--;
	FOR(i, 1, N) {
		auto it = data.lower_bound({narr[i], {N, -1}});
		occ[narr[i]]--;
		it = data.lower_bound({narr[i], {-1, -1}});
		if ((*it).first == narr[i]) {
			pair<int, pii> newval = {narr[i] + (occ[narr[i]] == 0), {(*it).s.f, (*it).s.s + 1}};
			data.erase(it);
			data.insert(newval);
		} else {
			data.insert({narr[i], {narr[i], 1}});				
		}
	}
	
	for (pair<int, pii> x : data) remove_order.push_back({x.s.f, x.s.s});

	ll ans = 0;
	ll size = N;
	for (pair<int, pii> x : data) {
		ans += size;
		size -= x.s.s;
	}
	print(ans);
}
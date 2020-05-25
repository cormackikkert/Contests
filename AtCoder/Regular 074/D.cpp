#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  

  

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<ll, int>;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 

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
	vll arr (3 * N);
	F0R(i, 3 * N) cin >> arr[i];

	ordered_set lhs, rhs;
	for (int i = 0; i < N; ++i) lhs.insert({arr[i], i});
	for (int i = N; i < 3 * N; ++i) rhs.insert({arr[i], i});

	ll lhsBest = 0;
	ll rhsBest = 0;

	auto i1 = lhs.begin(), i2 = rhs.begin();
	for (int i = 0; i < N; ++i) {
		lhsBest += (*i1).first;
		rhsBest += (*i2).first;
		i1 = next(i1), i2 = next(i2);
	}

	ll best = lhsBest - rhsBest;

	for (int i = N; i < 2 * N; ++i) {
		pii swap = {arr[i], i};
		if (rhs.order_of_key(swap) < N) {
			rhsBest -= swap.first; 
			rhsBest += (*rhs.find_by_order(N)).first;
		}
		if ((*lhs.find_by_order(lhs.size() - N)).first < swap.first) {
			lhsBest -= (*lhs.find_by_order(lhs.size() - N)).first;
			lhsBest += swap.first;
		}

		lhs.insert(swap);
		rhs.erase(rhs.find(swap));

		best = max(best, lhsBest - rhsBest);
	}
	print(best);
}
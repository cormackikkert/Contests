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
	vi arr (N + 2);
	F0R(i, N) cin >> arr[i + 1];

	vll lcum (N);
	vll rcum (N);
	stack<pair<int, ll>> deck; 
	deck.push({-1, 0});

	F0R(i, N) {
		while (deck.size() && arr[deck.top().first + 1] >= arr[i + 1]) deck.pop();

		ll newarea = 1LL * (i - deck.top().first) * arr[i + 1];
		lcum[i] = deck.top().second + newarea;

		deck.push({i, deck.top().second + newarea});
	}

	deck = stack<pair<int, ll>>();
	deck.push({N, 0});

	R0F(i, N) {
		while (deck.size() && arr[deck.top().first + 1] >= arr[i + 1]) deck.pop();

		ll newarea = 1LL * (deck.top().first - i) * arr[i + 1];
		rcum[i] = deck.top().second + newarea;

		deck.push({i, deck.top().second + newarea});
	}

	ll best = 0;
	ll bestInd = -1;
	F0R(i, N) {
		ll ns = lcum[i] + rcum[i] - arr[i + 1];
		if (ns > best) {
			best = ns;
			bestInd = i;
		}
	}

	
	vi ans (N);

	int lh = arr[bestInd + 1];
	for (int i = bestInd; i < N; ++i) {
		lh = min(lh, arr[i + 1]);
		ans[i] = lh;
	}

	lh = arr[bestInd + 1];
	for (int i = bestInd; i >= 0; --i) {
		lh = min(lh, arr[i + 1]);
		ans[i] = lh;
	}

	for (int i = 0; i < N; ++i) {
		cout << ans[i] << " ";
	}
}
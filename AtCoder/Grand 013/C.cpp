#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;

using vb = vector<bool>;
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

ll N, L, T;
vll solve(vll pos, vb dir) {
	ll s = 0;
	while (s < N && !dir[s]) ++s;

	if (s == N) {
		// all facing the same way case
		vll ans (N);
		F0R(i, N) {
			ans[i] = ((pos[i] - T) % L + L) % L;
		}
		return ans;
	}

	ll opp = 0;
	F0R(i, N) if (!dir[i]) ++opp;

	ll bumps = opp * ((2 * T) / L);

	F0R(i, N) if (!dir[i]) {
		ll dist = 0;
		if (pos[i] < pos[s]) 
			dist = L - pos[s] + pos[i];
		else
			dist = pos[i] - pos[s];
		if (dist < ((2 * T) % L)) bumps++;
	}

	vll ans (N);
	vll spots (N);
	F0R(i, N) {
		ll npos;
		if (dir[i])
			npos = (pos[i] + T) % L;
		else
			npos = (((pos[i] - T) % L) + L) % L;
		spots[i] = npos;
	}
	sort(spots.begin(), spots.end());
	int i = 0; 
	while (spots[i] != (pos[s] + T) % L) ++i;
	F0R(j, N) ans[(s + bumps + j) % N] = spots[(i + j) % N];
	return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> L >> T;
	vll pos (N);
	vb dir (N); // is clockwise
	F0R(i, N) {
		ll x, d; cin >> x >> d;
		pos[i] = x;
		dir[i] = (d == 1);
	}
	
	vll ans = solve(pos, dir);
	
	for (ll x : ans) print(x);
}
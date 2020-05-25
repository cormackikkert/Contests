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

void solve() {
	int N; cin >> N;
	vector<pair<int, int>> segs;
	vector<pair<int, int>> orig;
	F0R(i, N) {
		int l, r; cin >> l >> r;
		segs.push_back(pii {r, l});
		orig.push_back(pii {l, r});
	}
	sort(segs.begin(), segs.end());

	map<pii, char> res;
	int CT = -1;
	int JT = -1;
	for (pair<int, int> s : segs) {
        pair<int, int> seg = {s.second, s.first};
		if ((max(CT, JT) <= seg.first && CT > JT) || (CT <= seg.first)) {
			CT = seg.second;
			res[seg] = 'C';
		} else if (JT <= seg.first) {
			JT = seg.second;
			res[seg] = 'J';
		} else {
			cout << "IMPOSSIBLE"; return;
		}
	}
	string ans;
	for (pii seg : orig) {
		ans += res[seg];
	}
	cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	F0R(i, T) {
		cout << "Case #" << i + 1 << ": ";
		solve();
		cout << endl;
	}
}
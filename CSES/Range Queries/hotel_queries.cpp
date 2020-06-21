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

struct Seg {
	int N; 
	vi seg;

	void init(int N_) {
		N = N_; seg = vi (2*N);
	}

	void update(int i, int val) {
		seg[i += N] = val;
		for (i /= 2; i; i /= 2) seg[i] = max(seg[2*i], seg[2*i+1]);
	}

	int query(int l, int r) {
		int res = 0;
		for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
			if (l&1) res = max(res, seg[l++]);
			if (r&1) res = max(res, seg[--r]);
		}
		return res;
	}

	int getIndex(int val) {
		int cur = 1; 
		while (cur < N) {
			if (seg[2*cur] >= val) cur = 2*cur;
			else cur = 2*cur + 1;
		}
		return cur - N;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	Seg seg; seg.init(1 << 18);
	F0R(i, N) {
		int val; cin >> val; 
		seg.update(i, val);
	}

	F0R(i, M) {
		int rem; cin >> rem; 
		int ind = seg.getIndex(rem);
		if (seg.seg[ind + seg.N] < rem) {
			cout << 0 << " ";
		} else {
			cout << ind + 1 << " ";
			seg.update(ind, seg.seg[ind + seg.N] - rem);
		}
	}
	cout << endl;
}
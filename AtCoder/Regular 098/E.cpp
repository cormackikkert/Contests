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

template<class T> struct SumSeg { 
	const T ID = 0; // comb(ID,b) must equal b
	T combine(T a, T b) { return a+b; } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID);}

	void update(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) seg[p] = combine(seg[2*p], seg[2*p+1]);
	}
    
	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = combine(ra,seg[l++]);
			if (r&1) rb = combine(seg[--r],rb);
		}
		return combine(ra,rb);
	}
};

vi arr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K, Q; cin >> N >> K >> Q;
	
	arr.resize(N);
	F0R(i, N) cin >> arr[i];

	vi perm (N);
	F0R(i, N) perm[i] = i;
	sort(perm.begin(), perm.end(), [] (const auto& lhs, const auto& rhs) { 
		return arr[lhs] < arr[rhs];
	});

	int best = 1e9;
	F0R(i, N-Q+1) {
		SumSeg<int> sumSeg; sumSeg.init(N);
		SumSeg<int> minSeg; minSeg.init(N);
		F0R(j, i) minSeg.update(perm[j], 1);

		int cur = i;
		int C = Q;

		int hi = arr[perm[cur]];

		while (C) {
			int j = perm[cur];

			// left binary search
			int l1 = 0;
			int h1 = j;
			while (l1 < h1) {
				int m = l1 + (h1 - l1) / 2;
				if (minSeg.query(m, j) != 0) {
					l1 = m + 1;
				} else {
					h1 = m;
				}
			}

			int l2 = j;
			int h2 = N - 1;
			while (l2 < h2) {
				int m = l2 + (h2 - l2 + 1) / 2;
				if (minSeg.query(j, m) != 0) {
					h2 = m - 1;
				} else {
					l2 = m;
				}
			}

			int dist = l2 - l1 + 1;
			int remo = sumSeg.query(l1, l2);
			if (dist - remo >= K) {
				// remove
				hi = arr[j];
				C--;
				sumSeg.update(j, 1);
			} else {
				// dont remove
				if (C == Q) break;
				minSeg.update(j, 1);
			}

			++cur;
			if (cur >= N) break;
		}
		if (C == 0) {
			best = min(best, hi - arr[perm[i]]);
		}
	}
	print(best);

}
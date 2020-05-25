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

template<class T> struct Seg { 
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

int N;

vi solve(vi row) {
	vi res (N);
	Seg<int> seg; seg.init(N);
	vector<pii> newarr (N);
	F0R(i, N) newarr[i] = {row[i], i};
	sort(newarr.rbegin(), newarr.rend());
	for (pii data : newarr) {
		int i = data.second;
		res[i] = min(seg.query(0, i), seg.query(i, N-1));
		seg.update(i, 1);
	}
	return res;
}

vector<vi> calc(vector<vi> grid) {
	vector<vi> d1 (N, vi (N));
	F0R(i, N) {
		vi row = grid[i];
		vi res = solve(row);
		F0R(j, N) d1[i][j] = res[j];
	}
	return d1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N;
	vector<vi> arr1 (N, vi (N));
	vector<vi> arr2 (N, vi (N));
	F0R(i, N*N) {
		int x; cin >> x; --x;
		arr1[x/N][x%N] = i;
	}
	F0R(i, N) F0R(j, N) {
		arr2[i][j] = arr1[j][i];
	}

	vector<vi> data1 = calc(arr1);
	vector<vi> data2 = calc(arr2);
	
	int ans = 0;

	vector<vi> rrr (N, vi (N));
	F0R(i, N) F0R(j, N) {
		rrr[i][j] = data2[j][i];
		ans += min(data1[i][j], data2[j][i]);
	}
	for (vi x : rrr) print(x);
	print(ans);
}
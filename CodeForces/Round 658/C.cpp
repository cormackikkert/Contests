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

int N, X, Y;
vi arr;

int count(int occ) {
	map<int, int> cum; 
	int use = 0;
	F0R(i, N) {
		cum[arr[i]]++;
		if (cum[arr[i]] <= occ) ++use;
	}
	return use;
}

void solve() {
	cin >> N >> X >> Y;
	
	arr.resize(N);
	F0R(i, N) cin >> arr[i];

	if (Y < X) {print("NO"); return;}

	int lo = 0;
	int hi = N;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (count(mid) >= N - X) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}

	int rem = N - X;
	if (rem - max(0, 2*lo-rem) < Y - X) {print("NO"); return;}

	vector<bool> use (N+2);
	F0R(i, N) use[arr[i]] = true;
	int empty = 1;
	while (use[empty]) ++empty;

	vi alice (N, -1);
	map<int, int> cum;

	vi perm;

	F0R(i, N) {
		cum[arr[i]]++;
		if (cum[arr[i]] <= lo && perm.size() < N - X) perm.push_back(i);
	}

	sort(perm.begin(), perm.end(), [](const auto& lhs, const auto& rhs) {
		return arr[lhs] < arr[rhs];
	});

	int cnt = Y - X;
	F0R(i, perm.size()) {
		if (cnt && (arr[perm[i]] != arr[perm[(i+lo) % perm.size()]])) {
			alice[perm[i]] = arr[perm[(i + lo) % perm.size()]];
			--cnt;
		}
		else 
			alice[perm[i]] = empty;
	}

	F0R(i, N) if (alice[i] == -1) alice[i] = arr[i];
	print("YES");
	for (int x : alice) cout << x << " ";
	cout << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	F0R(i, T) solve();
}

/*
1
6 1 3
3 1 1 1 1 1
---
1 2 2 3 2 1
*/

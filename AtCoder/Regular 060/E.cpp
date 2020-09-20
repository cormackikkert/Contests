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
	vi arr (N);
	F0R(i, N) cin >> arr[i];
	int L; cin >> L;

	vector<vi> far (N, vi (31)); // farthest point you can end up
	int r = 0;
	int sum = 0;
	for (int l = 0; l < N; ++l) {
		while (r+1 < N && sum + arr[r+1] - arr[r] <= L) {
			sum += arr[r+1] - arr[r];
			++r;
		}
		far[l][1] = r;
		if (l + 1 < N) sum -= arr[l+1] - arr[l];
	}
	for (int j = 2; j <= 30; ++j) {
		for (int i = 0; i < N; ++i) {
			far[i][j] = far[far[i][j-1]][j-1];
		}
	}
	int Q; cin >> Q;
	F0R(i, Q) {
		int a, b; cin >> a >> b; --a; --b;
		if (a > b) swap(a, b);
		int ans = 0;
		for (int x = 30; x > 0; --x) {
			if (far[a][x] < b) {
				ans += 1 << (x-1);
				a = far[a][x];
			}
		}
		print(ans+1);
	}
}
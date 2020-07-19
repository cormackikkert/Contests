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
	
	int best = 1e9;

	int N; cin >> N;
	vector<vi> oarr (2, vi (N));
	F0R(i, N) cin >> oarr[1][i];
	F0R(i, N) cin >> oarr[0][i];

	for (int b = 0; b < (1 << N); ++b) {
		vector<vi> arr = oarr;
		
		int ans = 0;
		bool fail = false;
		vi newnums (N);
		vi col (N, 1);
		vi mask (N);
		F0R(i, N) mask[i] = (b & (1 << i)) > 0;

		F0R(i, N) newnums[i] = arr[mask[i]][i];
		sort(newnums.begin(), newnums.end());
	
		F0R(i, N) {
			int j = i;
			while (j < N) {
				int ncol = ((j-i)%2) ? 1 - col[j] : col[j];
				if ((newnums[i] == arr[mask[j]][j]) && (ncol == mask[j])) break;
				++j;
			}
			if (j == N) {
				fail = true; break;
			}

			swap(arr[0][i], arr[0][j]);
			swap(arr[1][i], arr[1][j]);
			swap(mask[i], mask[j]);
			swap(col[i], col[j]);
			
			for (int k = j - 1; k >= i; --k) {
				++ans;
				col[k] = 1 - col[k];
			}
		}
		if (!fail) best = min(best, ans);
	}
	print((best < 1e9) ? best : -1);
}
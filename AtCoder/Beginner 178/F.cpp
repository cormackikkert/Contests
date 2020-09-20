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

vi a;
vi b;
map<int, int> aocc;
map<int, int> bocc;
map<int, int> intersect;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	a.resize(N);
	b.resize(N);
	F0R(i, N) cin >> a[i];
	F0R(i, N) cin >> b[i];
	
	F0R(i, N) {
		aocc[a[i]]++;
		bocc[b[i]]++;
	}

	int I = 0;
	int H = 0;
	int ac = 0;
	for (pair<int, int> key : aocc) {
		intersect[key.first] = min(key.second, bocc[key.first]); 
		int intersection = intersect[key.first];
		I += intersection;
		if (intersection > H) {
			ac = key.first;
		}
		H = max(H, intersection);
	}

	if (2 * H > N) {
		print("No");
	} else if (2 * H > I) {
		vi ans (N, -1);
		for (int i = 0; i < N; ++i) {
			if (bocc[ac] && a[i] != ac && intersect[a[i]]) {
				bocc[ac]--;
				ans[i] = ac;
			}
		}

		for (int i = 0; i < N; ++i) {
			if (bocc[ac] && a[i] != ac) {
				bocc[ac]--;
				ans[i] = ac;
			}
		}

		vi bi;
		vi birem;
		map<int, int> bcopy = intersect;
		F0R(i, N) if (b[i] != ac) {
			if (bcopy[b[i]] > 0) {
				bi.push_back(b[i]);
				bcopy[b[i]]--;
			}
			else birem.push_back(b[i]);
		}

		for (int i = 0; i < N; ++i) {
			if (a[i] == ac && bi.size()) {
				ans[i] = bi.back();
				bi.pop_back();
			}
		}

		int j = 0;
		for (int i = 0; i < N; ++i) {
			if (ans[i] == -1) {
				if (j >= birem.size()) {
					print("No"); return 0;
				}
				ans[i] = birem[j++];
			}
		}

		print("Yes");
		for (int x : ans) cout << x << " ";
		cout << endl;
		
	} else {
		vi ans (N, -1);
		vi ai;
		
		map<int, int> acopy = intersect;
		F0R(i, N) if (acopy[a[i]] > 0) {
			ai.push_back(i);
			acopy[a[i]]--;
		}
		vi bi;
		vi birem;
		int j = 0;
		map<int, int> bcopy = intersect;
		F0R(i, N) {
			if (bcopy[b[i]] > 0) {
				bi.push_back(b[i]);
				bcopy[b[i]]--;
			}
			else birem.push_back(b[i]);
		}
		sort(ai.begin(), ai.end(), [] (const auto& lhs, const auto& rhs) {
			int il = intersect[a[lhs]];
			int ir = intersect[a[rhs]];
			return (il > ir) || ((il == ir) && (a[lhs] > a[rhs])); 
		});
		sort(bi.begin(), bi.end(), [] (const auto& lhs, const auto& rhs) {
			int il = intersect[lhs];
			int ir = intersect[rhs];
			return (il > ir) || ((il == ir) && (lhs > rhs)); 
		});

		for (int i = 0; i < ai.size(); ++i) {
			ans[ai[(i + H)%ai.size()]] = bi[i];
		}
		// print(ans);

		// print(ans);
		for (int i = 0; i < N; ++i) if (ans[i] == -1) {
			ans[i] = birem[j++];
		}
		print("Yes");
		for (int x : ans) cout << x << " ";
		cout << endl;
		

	}
}
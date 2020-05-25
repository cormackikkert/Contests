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
	string S; cin >> S;

	vi RC (N + 1);
	vi GC (N + 1);
	vi BC (N + 1);

	R0F(i, N) {
		if (S[i] == 'R') {
			RC[i] = 1;
		} else if (S[i] == 'G') {
			GC[i] = 1;
		} else if (S[i] == 'B') {
			BC[i] = 1;
		}
		RC[i] += RC[i+1];
		GC[i] += GC[i+1];
		BC[i] += BC[i+1];
	}

	ll sum = 0;

	F0R(i, N) {
		FOR(j, i+1, N) {
			if (S[i] == S[j]) continue;
			char lo = min(S[i], S[j]);
			char hi = max(S[i], S[j]);
			if (lo == 'B' && hi == 'G') {
				sum += RC[j+1];
				if (j + (j - i) < N && S[j + j - i] == 'R') --sum;
			} else if (lo == 'B' && hi == 'R') {
				sum += GC[j+1];
				if (j + (j - i) < N && S[j + j - i] == 'G') --sum;
			} else if (lo == 'G' && hi == 'R') {
				sum += BC[j+1];
				if (j + (j - i) < N && S[j + j - i] == 'B') --sum;
			}
		}
	}
	print(sum);
}
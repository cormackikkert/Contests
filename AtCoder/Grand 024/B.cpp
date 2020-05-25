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
	vi ind (N);
	F0R(i, N) ind[arr[i]-1] = i;

	int best = N-1;
	
	vi scores (N+1);
	set<int> seq;
	int lastIndex = -1;
	int curDown = 0;
	F0R(r, N) {
		seq.insert(ind[r]);
		auto it = seq.find(ind[r]);
		if (it != seq.begin() && (*prev(it)) == lastIndex && prev(it) == seq.begin()) {
			curDown += 1;
		} else if (it == seq.begin()) {
			curDown = 1;
		} else {
			curDown = 0;
		}
		lastIndex = ind[r];
		print("CALC", seq, r+2, curDown, r + 1 - curDown);
		scores[r+2] = r + 1 - curDown;
	}
	print(arr);
	print(scores);
	FOR(i, 2,N+1) best = min(best,((scores[i] == 0) ? scores[i+1] : scores[i]) + (N-i));

	print(best);
}
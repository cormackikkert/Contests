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
	int N, A, B; cin >> N >> A >> B; swap(A, B);

	if (A + B == N + 1) {
		vi arr (N);
		F0R(i, B - 1) arr[i] = 1 + i;
		FOR(i, B - 1, N) arr[i] = N - (i - B + 1);
		for (int x : arr) cout << x << " ";
		cout << endl;
		return 0;
	}
	
	if (A + B > N + 1) {
		cout << -1 << endl;
		return 0;
	}

	vi arr (N);
	int onLeft = 0;
	while (true) {
		F0R(i, A) arr[onLeft * A + i] = A - i + onLeft * A;
		--B;
		if (B < 0) {
			cout << -1 << endl;
			return 0;
		}
		++onLeft;
		if (N - onLeft * A - B < A) break;
	}
	int gap = N - onLeft * A - B;
	if (gap > 0 && B == 0) {cout << -1 << endl; return 0;}
	F0R(i, B) {
		arr[N-1-i] = N - i - gap;
	}
	
	int hi = N;
	for (int x = onLeft * A; x < N && arr[x] == 0; ++x) {
		arr[x] = hi; --hi; 
	}

	for (int x : arr) cout << x << " ";
	cout << endl;
}
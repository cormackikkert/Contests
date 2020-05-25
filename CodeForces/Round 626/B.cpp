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
	ll N, M, K; cin >> N >> M >> K;
	
	vi arr1 (N);
	F0R(i, N) cin >> arr1[i];

	vi arr2 (M);
	F0R(i, M) cin >> arr2[i];

	ll ans = 0;

	vi occ1;
	F0R(i, N) if (arr1[i] != 0) {
		int j = i;
		while (j < N && arr1[j] == 1) ++j;
		occ1.push_back(j-i);
		i = j - 1;
	}

	vi occ2;
	F0R(i, M) if (arr2[i] != 0) {
		int j = i;
		while (j < M && arr2[j] == 1) ++j;
		occ2.push_back(j-i);
		i = j - 1;
	}

	sort(occ1.begin(), occ1.end());

	sort(occ2.begin(), occ2.end());

	vi cumsum1 (occ1.size() + 1);
	F0R(i, occ1.size()) cumsum1[i+1] = cumsum1[i] + occ1[i];

	vi cumsum2 (occ2.size() + 1);
	F0R(i, occ2.size()) cumsum2[i+1] = cumsum2[i] + occ2[i];

	FOR(i, 1, K) if (K % i == 0) {
		int i1 = lower_bound(occ1.begin(), occ1.end(), i) - occ1.begin();
		int xpos = cumsum1[occ1.size()] - cumsum1[i1] - (i - 1) * (occ1.size() - i1);

		int i2 = lower_bound(occ2.begin(), occ2.end(), K/i) - occ2.begin();
		int ypos = cumsum2[occ2.size()] - cumsum2[i2] - (K/i - 1) * (occ2.size() - i2);

		ans += 1LL * xpos * ypos;
	}	

	print(ans);
}
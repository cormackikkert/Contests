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
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	string S; cin >> S;
	string T; cin >> T;

	int S1 = 0;
	int T1 = 0;
	F0R(i, N) {
		if (S[i] == '1') ++S1;
		if (T[i] == '1') ++T1;
	}

	if (S1 != T1) {
		print(-1);
		return 0;
	}

	set<int> bad0s;
	set<int> bad1s;
	F0R(i, N) if (S[i] != T[i]) {
		if (S[i] == '0') bad0s.insert(i);
		else bad1s.insert(i);
	}

	int cnt = 0;
	while (bad0s.size() != 0 || bad1s.size() != 0) {
		// print("HERE", bad0s, bad1s);
		auto it0 = bad0s.end(); --it0;
		auto it1 = bad1s.end(); --it1;
		int i0 = *it0;
		int i1 = *it1;
		
		bool lookForOne = false;
		int ind = -1;

		auto it = bad0s.begin();

		if (i0 > i1) {
			ind = i0;
			it = it0;	
			lookForOne = true;
		} else {
			ind = i1;
			it = it1;
			lookForOne = false;
		}

		bool orig = !lookForOne;
		

		while (bad0s.size() || bad1s.size()) {
			if (lookForOne) {
				// print(bad1s);
				auto tmp = bad1s.lower_bound(ind);
				if (tmp == bad1s.begin()) {
					if (lookForOne == orig) {
						bad0s.erase(it);
					}
					break;
				};
				bad0s.erase(it);
				tmp--;
				it = tmp;
				ind = *it;
				
			} else {
				auto tmp = bad0s.lower_bound(ind);
				if (tmp == bad0s.begin()) {
					if (lookForOne == orig) {
						bad1s.erase(it);
					}
					break;
				}
				bad1s.erase(it);
				tmp--;
				it = tmp;
				ind = *it;
				
			}
			// print(ind);
			lookForOne = !lookForOne;
		}
		++cnt;
	}
	assert (bad0s.size() == 0 && bad1s.size() == 0);
	print(cnt);
}
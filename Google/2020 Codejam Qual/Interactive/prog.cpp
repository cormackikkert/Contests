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

int B;

int queries = 1;
int ask(int pos) {
	cout << pos + 1 << endl;
	fflush(stdout);
	int ans; cin >> ans;
	++queries;
	return ans;
}

bool solve() {
	queries = 1;
	int same = -1;
	int diff = -1;
	vi arr (B);
	int l = 0;
	int h = B - 1;
	while (l <= h) {
		if (queries > 1 && queries % 10 == 1) {
			// deal with stuff
			if (same != -1 && diff != -1) {
				if (ask(same) == arr[same]) {
					if (ask(diff) == arr[diff]) {

					} else {
						reverse(arr.begin(), arr.end());
					}
				} else {
					if (ask(diff) == arr[diff]) {
						// compliment + reverse
						reverse(arr.begin(), arr.end());
						F0R(i, B) arr[i] = 1 - arr[i];
					} else {
						// compliment
						F0R(i, B) arr[i] = 1 - arr[i];
					}
				}
			} else if (same == -1) {
				// diff != -1
				if (ask(diff) == arr[diff]) {
					// comp + reverse
					
					// if (B % 2 == 1)
					// arr[B/2] = ask(B/2);
				} else {
					reverse(arr.begin(), arr.end());
					// F0R(i, B) arr[i] = 1 - arr[i];
					// arr[B/2] = ask(B/2);
				}
				ask(0);
			} else {
				if (ask(same) == arr[same]) {
					
					// comp + reverse
					// reverse(arr.begin(), arr.end());
					// if (B % 2 == 1)
					// arr[B/2] = ask(B/2);
				} else {
					F0R(i, B) arr[i] = 1 - arr[i];
					// arr[B/2] = ask(B/2);
				}
				ask(0);
			}
		}

		if (queries % 10 < 10) {
			arr[l] = ask(l); ++l;
			if (l <= h) {arr[h] = ask(h); --h;}
			if (l < h + 1) {
				if (same == -1 && arr[l-1] == arr[h+1]) same = l-1;
				if (diff == -1 && arr[l-1] != arr[h+1]) diff = l-1;
			}
		} else {
			while (queries % 10 != 1) ask(0);
		}
	}
	string ans = "";
	for (int x : arr) ans += to_string(x);
	cout << ans << endl;
	fflush(stdout);
	char c; cin >> c;
	return (c == 'Y');
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T >> B;
	F0R(i, T) {
		if (!solve()) return 0;
	}
}
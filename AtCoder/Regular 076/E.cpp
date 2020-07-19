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

int R, C, N;
bool onPerimeter(int x, int y) {
	return (x == 0 || x == C) || (y == 0 || y == R);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	 
	cin >> C >> R >> N;

	vector<pii> top, right, bottom, left;

	F0R(i, N) {
		int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		if (onPerimeter(x1, y1) && onPerimeter(x2, y2)) {
			for (pii point : vector<pii> {{x1, y1}, {x2, y2}}) {
				int x = point.first;
				int y = point.second;
				if (y == 0) {
					top.push_back({x, i});
				} else if (x == C) {
					right.push_back({y, i});
				} else if (y == R) {
					bottom.push_back({x, i});
				} else {
					left.push_back({y, i});
				}
			}
		}
	}
	sort(top.begin(), top.end());
	sort(right.begin(), right.end());
	sort(bottom.rbegin(), bottom.rend());
	sort(left.rbegin(), left.rend());

	vi everything;
	for (pii x : top) everything.push_back(x.second);
	for (pii x : right) everything.push_back(x.second);
	for (pii x : bottom) everything.push_back(x.second);
	for (pii x : left) everything.push_back(x.second);
	
	vi stack; 
	for (int x : everything) {
		if (stack.size() && stack.back() == x) {
			stack.pop_back();
		} else {
			stack.push_back(x);
		}
	}

	print((stack.size() == 0) ? "YES" : "NO");
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define f first
#define s second

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
	vector<pii> points (N);
	vi flip (N);
	F0R(i, N) {
		int x, y; cin >> x >> y;
		if (x < 0) flip[i] |= 1;
		if (y < 0) flip[i] |= 2;
		points[i] = {abs(x), abs(y)};
	}

	vector<string> ans (N);
	vi sizes;

	F0R(i, N) if (((points[0].f^points[0].s)&1) != ((points[i].f^points[i].s)&1)) {print(-1); return 0;}
	
	if (((points[0].f^points[0].s)&1) == 0) {
		sizes.push_back(1); sizes.push_back(1);
		F0R(i, N) {
			if ((points[i].first&1) == 0) {
				ans[i] += "LR";
			} else {
				ans[i] += "RU";
			}
		}
	} else {
		sizes.push_back(1);
		F0R(i, N) {
			if (points[i].first&1) {
				ans[i] += "R";
			} else {
				ans[i] += "U";
			}
		}
	}
	F0R(i, N) points[i].first /= 2, points[i].second /= 2;

	int s = 1;
	while (true) {
		bool allZero = true;
		for (pii x : points) allZero &= (x.first == 0) && (x.second == 0);
		if (allZero) break;
		
		sizes.push_back(1 << (s-1));
		sizes.push_back(1 << (s-1));
		sizes.push_back(1 << (s-1));
		sizes.push_back(1 << (s-1));
		F0R(i, N) {
			if ((points[i].first&1)==0 && (points[i].second&1)==0) {
				ans[i] += "LRLR"; // 00
			} else if ((points[i].first&1)==0 && (points[i].second&1)==1) {
				ans[i] += "LRUU"; // 01
			} else if ((points[i].first&1)==1 && (points[i].second&1)==0) {
				ans[i] += "RRLR"; // 10
			} else {
				ans[i] += "RRUU"; // 11
			}
		}
		F0R(i, N) points[i].first /= 2, points[i].second /= 2;
		++s;
	}	
	print(sizes.size());
	for (int s : sizes) cout << s << " ";
	cout << endl;
	F0R(i, N) {
		if (flip[i] & 1) {
			replace(ans[i].begin(), ans[i].end(), 'L', 'X');
			replace(ans[i].begin(), ans[i].end(), 'R', 'L');
			replace(ans[i].begin(), ans[i].end(), 'X', 'R');
		}
		if (flip[i] & 2) {
			replace(ans[i].begin(), ans[i].end(), 'D', 'X');
			replace(ans[i].begin(), ans[i].end(), 'U', 'D');
			replace(ans[i].begin(), ans[i].end(), 'X', 'U');
		}
		print(ans[i]);
	}
}
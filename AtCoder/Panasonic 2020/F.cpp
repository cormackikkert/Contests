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

void solve() {
	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

	ll scale = pow(3, 29);
	ROF(d, 0, 30) {
		ll nx1 = x1 % (3 * scale);
		ll nx2 = x2 % (3 * scale);
		ll ny1 = y1 % (3 * scale);
		ll ny2 = y2 % (3 * scale);
	
		if (scale - 1 < nx1 && nx1 < 2 * scale && scale - 1< nx2 && nx2 < 2 * scale &&
			min(ny1, ny2) < scale && 2 * scale - 1 < max(ny1, ny2)) {
			
			ll buildY;
			if (nx1 - scale + nx2 - scale < 2 * scale + 1 - nx1 + 2 * scale + 1 - nx2) {
				buildY = scale;
			} else {
				buildY = scale + 1;
			}

			ll dist = abs(y1 - buildY) + abs(y2 - buildY) + abs(y1 - y2);
			print(dist);
			return;
		}
		scale /= 3;
	}

	scale = pow(3, 29);
	ROF(d, 0, 30) {
		ll ny1 = x1 % (3 * scale);
		ll ny2 = x2 % (3 * scale);
		ll nx1 = y1 % (3 * scale);
		ll nx2 = y2 % (3 * scale);
	
		if (scale - 1 < nx1 && nx1 < 2 * scale && scale - 1< nx2 && nx2 < 2 * scale &&
			min(ny1, ny2) < scale && 2 * scale - 1 < max(ny1, ny2)) {
			
			ll buildY;
			if (nx1 - scale + nx2 - scale < 2 * scale + 1 - nx1 + 2 * scale + 1 - nx2) {
				buildY = scale;
			} else {
				buildY = scale + 1;
			}

			ll dist = abs(y1 - buildY) + abs(y2 - buildY) + abs(y1 - y2);
			print(dist);
			return;
		}
		scale /= 3;
	}

	print(abs(x1 - x2) + abs(y1 - y2));
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	F0R(i, Q) solve();
}
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

int N, K;
vector<pair<pair<int, int>, int>> circs;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	circs.resize(N);
	F0R(i, N) {
		int x, y, z; cin >> x >> y >> z;
		circs[i] = {{x, y}, z};
	}
	ld ans = INFINITY;

	F0R(i, N) {
		FOR(j, i+1, N) {
			ld x1 = circs[i].first.first;
			ld y1 = circs[i].first.second;
			ld c1 = circs[i].second;

			ld x2 = circs[j].first.first;
			ld y2 = circs[j].first.second;
			ld c2 = circs[j].second;

			ld radius = c1 * c2 * sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) / (c1 + c2);

			// Find times
			ld vx = x2 - x1;
			ld vy = y2 - y1;
			ld mag = sqrt(vx*vx+vy*vy);
			vx /= mag;
			vy /= mag;

			ld X = x1 + vx * radius / c1;
			ld Y = y1 + vy * radius / c1;

			// print("HERE", i+1, j+1, X, Y, radius);

			vector<ld> times;
			F0R(c, N) {
				ld cx = circs[c].first.first;
				ld cy = circs[c].first.second;
				ld cc = circs[c].second;
				times.push_back(cc * sqrt(pow(X - cx, 2) + pow(Y - cy, 2)));
			}
			sort(times.begin(), times.end());
			ans = min(ans, times[K-1]);
		}
	}
	if (K > 2)
		cout << setprecision(50) << ans << endl;
	else {
		cout << 1 << endl;
	}
	// print(ans);
}
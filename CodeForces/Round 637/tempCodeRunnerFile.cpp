#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
	int N, M; cin >> N >> M;
	vi DS (M);
	F0R(i, M) cin >> DS[i];
	sort(DS.begin(), DS.end());

	int G, R; cin >> G >> R;
	
	// dijkstra
	vector<vll> dist (M, vll (G + R, INF));
	using data = pair<ll, pair<int, int>>;
	priority_queue<data, vector<data>, greater<data>> q;
	dist[0][0] = 0;
	q.push({0, {0, 0}});
	while (!q.empty()) {
		pair<ll, ll> v = q.top().second;
		ll d = q.top().first;
		
		int pos = v.f;
		int time = v.s;

		q.pop();

		if (d != dist[pos][time]) continue;

		if (pos == M - 1) {
			print(d);
			return 0;
		}

		if (time >= G) {
			pii ns = {pos, 0};
			if (d + (R + G - time) < dist[ns.f][ns.s]) {
				dist[ns.f][ns.s] = d + (R + G - time);
				q.push({dist[ns.f][ns.s], ns});			
			}
		} else {
			if (pos + 1 < M && DS[pos+1] - DS[pos] + time <= G) {
				pii ns = {pos + 1, (time + DS[pos+1] - DS[pos]) % (R + G)};
				if (d + DS[pos+1] - DS[pos] < dist[ns.f][ns.s]) {
					// print("GO RIGHT", DS[pos+1] - DS[pos] + time);
					dist[ns.f][ns.s] = d + DS[pos+1] - DS[pos];
					q.push({dist[ns.f][ns.s], ns});
				}
			} 
			if (pos - 1 >= 0 && DS[pos] - DS[pos-1] + time <= G) {
				pii ns = {pos - 1, (time + DS[pos] - DS[pos-1]) % (R + G)};
				if (d + DS[pos] - DS[pos-1] < dist[ns.f][ns.s]) {
					dist[ns.f][ns.s] = d + DS[pos] - DS[pos-1];
					q.push({dist[ns.f][ns.s], ns});
				}
			}
		}
	}
	print(-1);
}
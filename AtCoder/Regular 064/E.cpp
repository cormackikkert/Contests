#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define float long double
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

int N;

vector<vector<float>> graph;

float dijkstra(int p1, int p2) {
	vector<float> distance (N+2, INFINITY);
	vector<bool> visited (N+2);

	distance[p1] = 0;

	while (true) {
		int cur = -1;
		float dist = INFINITY;

		F0R(i, N+2) {
			if (visited[i]) continue;
			if (distance[i] < dist) {
				dist = distance[i]; cur = i;
			}
		}

		if (cur == -1) break;

		visited[cur] = true;

		F0R(i, N+2) {
			if (graph[cur][i] >= 0) {
				distance[i] = min(distance[i], graph[cur][i] + distance[cur]);
			}
		}
	}

	return distance[p2];
}

float dist(pair<pair<int, int>, float> c1, pair<pair<int, int>, float> c2) {
	int x1 = c1.first.first;
	int y1 = c1.first.second;
	int r1 = c1.second;

	int x2 = c2.first.first;
	int y2 = c2.first.second;
	int r2 = c2.second;

	return max(0.0, sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) - r1 - r2);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int XS, YS, XE, YE; cin >> XS >> YS >> XE >> YE;

	cin >> N;
	
	graph = vector<vector<float>> (N+2, vector<float> (N+2, -1.0));

	vector<pair<pair<int, int>, float>> circles;

	circles.push_back({{XS, YS}, 0});

	F0R(i, N) {
		int x, y, r; cin >> x >> y >> r;
		circles.push_back({{x, y}, r});
	}

	circles.push_back({{XE, YE}, 0});

	F0R(i, N + 2) {
		F0R(j, N + 2) {
			graph[i][j] = dist(circles[i], circles[j]);
		}
	}

	cout << setprecision(10) << dijkstra(0, N+1) << endl;
}
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

int N, K, L;
vector<vi> cGraph;
vector<vi> tGraph;

vi cRep;
vi tRep;

vector<bool> cSeen;
vector<bool> tSeen;

vi cSize;
vi tSize;
vi bSize;

vi tFound;

void cdfs(int cur, int rep) {
	cRep[cur] = rep;
	for (int n : cGraph[cur]) if (!cSeen[n]) {
		cSeen[n] = true;
		cdfs(n, rep);
	}
}

map<int, int> occ;
void tdfs(int cur, int rep) {
	tFound.push_back(cur);
	occ[cRep[cur]]++;
	for (int n : tGraph[cur]) if (!tSeen[n]) {
		tSeen[n] = true;
		tdfs(n, rep);
	}
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K >> L;

	cGraph.resize(N); tGraph.resize(N);
	cRep.resize(N); tRep.resize(N); cSeen.resize(N); tSeen.resize(N); cSize.resize(N); tSize.resize(N); bSize.resize(N);

	F0R(i, K) {
		int a, b; cin >> a >> b; --a; --b;
		cGraph[a].push_back(b);
		cGraph[b].push_back(a);
	}
	F0R(i, L) {
		int a, b; cin >> a >> b; --a; --b;
		tGraph[a].push_back(b);
		tGraph[b].push_back(a);
	}

	F0R(i, N) if (!cSeen[i]) {
		cSeen[i] = true;
		cdfs(i, i);
	}

	F0R(i, N) if (!tSeen[i]) {
		occ = map<int, int> ();
		tFound = vi ();
		tSeen[i] = true;
		tdfs(i, i);
		for (int x : tFound) {
			bSize[x] = occ[cRep[x]];
		}
	}
	F0R(i, N) cout << bSize[i] << " ";
}
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

const int maxN = 1e6+10;
int trie [maxN][26] = {0};
int trieEnds [maxN] = {0};
int trieInsert = 1;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<vi> SS (N);
	F0R(i, N) {
		string res; cin >> res;
		SS[i] = vector<int> (res.begin(), res.end());
		F0R(j, SS[i].size()) SS[i] -= 'a';
	}

	sort(SS.begin(), SS.end(), [](const auto& lhs, const auto& rhs) {
		return lhs.size() < rhs.size();
	});

	ll ans = 0;

	for (vi S : SS) {
		vi early (26, S.size());
		R0F(i, S.size()) early[i] = S[i];

		int node = 0;
		F0R(l, 26) if (early[l] < S.size() && trie[node][l] != 0) ans += trieEnds[node][l];

		R0F(i, S.size()) {
			int c = S[i];
			node = trie[node][c];
			if (node == 0) break;
			F0R(l, 26) if (early[l] < i && trie[node][l] != 0) ans += trieEnds[node][l];
		}

		// insert reverse thing
		int node = 0;
		R0F(i, S.size()) {
			int c = S[i];
			if (trie[node][c] == 0) trie[node][c] = trieInsert++;
			node = trie[node][c];
		}
		trieEnds[node]++;
	}
	print(ans);
}
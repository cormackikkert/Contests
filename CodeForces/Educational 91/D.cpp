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

ll X, K, Y; 
ll solve(ll total) {
	if (K * Y < X) {
		return Y * total;
	} else {
		return X * (total / K) + Y * (total % K);
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	cin >> X >> K >> Y;
	vi AS (N);
	vi BS (M);
	F0R(i, N) cin >> AS[i];
	F0R(i, M) cin >> BS[i];
	
	vector<pair<vi, int>> seqs;

	int i = 0;
	int j = 0;
	while (j < M) {
		vi current_seq;
		while (i < N && AS[i] != BS[j]) current_seq.push_back(AS[i++]);
		if (i == N) {
			// failed
			print(-1);
			return 0;
		}
		if (current_seq.size()) seqs.push_back({current_seq, max(BS[j], j ? BS[j-1] : -1)});
		++i;
		++j;
	}
	if (i < N) {
		vi temp_seq;
		while (i < N) temp_seq.push_back(AS[i++]);
		seqs.push_back({temp_seq, BS[j-1]});
	}
	int AMax = AS[0];
	F0R(i, N) AMax = max(AMax, AS[i]);

	ll ans = 0;
	for (pair<vi, int> data : seqs) {
		vi seq = data.first;
		int sideMax = data.second;

		int seqMax = seq[0];
		F0R(i, seq.size()) seqMax = max(seqMax, seq[i]);

		if (seqMax < sideMax) {
			ans += solve(seq.size());
		} else {
			if (seq.size() < K) {
				print(-1);
				return 0;
			}
			ans += X + solve(seq.size() - K);
		}
	}
	print(ans);
}
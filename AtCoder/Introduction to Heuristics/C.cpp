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

int N = 26, D;
vi last (N, -1);
vi CS (N);
vector<vi> SAT;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> D;
	F0R(i, N) cin >> CS[i];
	SAT = vector<vi> (D, vi (N));
	F0R(i, D) F0R(j, N) cin >> SAT[i][j];
	
	vi ans (D);
	vector<set<int>> occ (N);
	F0R(i, N) {
		occ[i].insert(-1);
		occ[i].insert(D);
	}

	int sat = 0;
	F0R(i, D) {
		int choice; cin >> choice; --choice;
		
		// precomp
		ans[i] = choice;
		occ[choice].insert(i);

		// calc
		sat += SAT[i][choice];
		last[choice] = i;
		F0R(j, N) sat -= CS[j] * (i - last[j]);
	}

	int M; cin >> M;
	F0R(i, M) {
		int day, choice, before, after; cin >> day >> choice; --day; --choice;

		int cur = ans[day]; 
		sat -= SAT[day][cur];
		sat += SAT[day][choice];		
		
		// reduce sat
		before = *(--occ[cur].lower_bound(day));
		after = *occ[cur].upper_bound(day);
		sat -= CS[cur] * (day - before) * (after - day);

		// increase sat
		before = *(--occ[choice].upper_bound(day));
		after = *occ[choice].upper_bound(day);
		sat += CS[choice] * (day - before) * (after - day);

		// update variables
		occ[cur].erase(day);
		occ[choice].insert(day);
		ans[day] = choice;

		print(sat);
	}	
}
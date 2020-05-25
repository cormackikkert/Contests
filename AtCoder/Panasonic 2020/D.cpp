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

vi arr;
int N;

vector<string> ans;

void recurse(int depth) {
	int pos = 0;
	while (pos < N && arr[pos] != 0) ++pos;

	if (pos == N) {
		// full, print string
		string res = "";
		for (int x : arr) res += 'a' + x - 1;
		ans.push_back(res);
	} else {
		arr[pos] = depth;
		int rem = 0;
		for (int x : arr) if (x == 0) ++rem;

		for (int x = 0; x < (1 << rem); ++x) {
			int o = x;

			vector<bool> update (N);
			int i = 0;
			while (o) {
				while (i < N && arr[i] != 0) ++i;
				if (o % 2 == 1) {
					update[i] = true;
					arr[pos] = depth;
				}
				++i;
				o /= 2;
			}

			recurse(depth + 1);

			F0R(i, N) if (update[i]) arr[i] = 0;
		}
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	arr.resize(N);
	recurse(1);
	print(ans);
}
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
		pr("{",x.first,", ",x.second,"}"); 
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

	map<char, ll> total;
	map<char, bool> begins;
	vector<string> strings;
	F0R(i, N) {
		string S; cin >> S;
		begins[S[0]] = true;
		reverse(S.begin(), S.end());
		strings.push_back(S);
		ll base = 1;
		
		F0R(i, S.size()) {
			total[S[i]] += base;
			base *= 10;
		}
	}

	vector<pair<ll, char>> res;
	for (auto x : total) res.push_back({x.second, x.first});
	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());
	map<char, int> biject;
	for (auto x : res) if (!begins[x.second]) {
		biject[x.second] = 0;
		break;
	}
	int digit = 1;
	for (auto x : res) if (biject.find(x.second) == biject.end()) {
		biject[x.second] = digit;
		++digit;
	}

	ll cumsum = 0;
	for (string s : strings) {
		ll base = 1;
		F0R(i, s.size()) {
			cumsum += biject[s[i]] * base;
			base *= 10;
		}
	}
	print(cumsum);

	
}
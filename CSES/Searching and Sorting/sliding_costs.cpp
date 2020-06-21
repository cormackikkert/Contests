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
	int N, K; cin >> N >> K;
	
	ll MAX = 1e9;

	vector<pii> arr (N);
	F0R(i, N) {
		int x; cin >> x;
		arr[i] = {x, i};
	}

	vector<pii> temp (K);
	F0R(i, K) temp[i] = arr[i];
	sort(temp.begin(), temp.end());
	pii median = temp[(K-1)/2];

	ll lSize = K - K / 2;
	ll rSize = K / 2;

	ll above = 0;
	ll below = 0;
	F0R(i, K) {
		pii x = arr[i];
		if (x <= median) below += MAX - x.first;
		else             above += x.first;
	}

	cout << above - median.f * rSize + below - (MAX - median.f) * lSize  << " ";

	set<pii> items;
	F0R(i, K) items.insert(arr[i]);

	for (int r = K; r < N; ++r) {
		int l = r - K;
		
		items.insert(arr[r]);

		if (arr[l] == median) {
			if (arr[r] > median) {
				// median moves up
				auto it = items.upper_bound(median);
				median = *it;

				if (median != arr[r]) {
					above -= median.f;
				}
			} else {
				// median moves down
				auto it = items.lower_bound(median); --it;
				median = *it;

				if (median != arr[r]) {
					below -= MAX - median.first;
				}
			}
		} else {
			if ((arr[l] <= median) == (arr[r] <= median)) {

			} else if ((arr[l] <= median) && (arr[r] > median)) {
				below += MAX - median.first;

				// median moves up
				auto it = items.upper_bound(median);
				median = *it;
				
				above -= median.first;

			} else {
				above += median.first;

				// median moves down
				auto it = items.lower_bound(median); --it;
				median = *it;

				below -= MAX - median.first;
			}
		}

		items.erase(items.find(arr[l]));

		if (arr[l] <= median) below -= MAX - arr[l].first;
		else             	  above -= arr[l].first;
		if (arr[r] <= median) below += MAX - arr[r].first;
		else             	  above += arr[r].first;

		cout << above - median.f * rSize + below - (MAX - median.f) * lSize  << " ";
	}
	cout << endl;
}
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
using pii = pair<int, int>;
using square = pair<pii, pii>;

ll INF = LLONG_MAX;

using vi = vector<int>;
using vll = vector<ll>;


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
	int N; cin >> N;
	vector<square> squares (N);
	vi ycoords (N);
	F0R(i, N) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		squares[i] = {pii {x1, y1}, pii {x2, y2}};
		ycoords.push_back(y1);
		ycoords.push_back(y2);
	}
	sort(ycoords.begin(), ycoords.end());
	auto it = unique(ycoords.begin(), ycoords.end());
	ycoords.resize(distance(ycoords.begin(), it));

	vector<pii> data (ycoords.size() + 1);
	data[0] = pii {-1, ycoords[0]};
	data[ycoords.size()] = pii {ycoords[ycoords.size() - 1], 1e9+1};
	FOR(i, 1, ycoords.size()) {
		data[i] = pii {ycoords[i-1], ycoords[i]};
	}

	vector<pair<int, pii>> vranges (2 * N); // (x pos, (ylo, yhi))
	F0R(i, N) {
		vranges.push_back({squares[i].f.f, {squares[i].f.s, squares[i].s.s}});
		vranges.push_back({squares[i].f.s, {squares[i].f.s, squares[i].s.s}});
	}

	sort(vranges.begin(), vranges.end());

	// sqrt decomp
	int len = (int) sqrt(data.size() + .0) + 1;
	vll colors (data.size());
	vll total (len);
	for (int i = 0; i < len; ++i) {
		ll s = 0;
		for (int j = i * len; j < min((i+1) * len, (int) data.size()); ++j) {
			s += data[j].s - data[j].f;
		}
		total[i] = s;
	}
	vll blackCount (len);
	vll parity (len);

	ll blackTotal = 0;
	for (int zzz = 0; zzz < vranges.size(); ++zzz) {
		// count sum
		ll allSum = 0;
		for (int i = 0; i < len; ++i) {
			ll sum = blackCount[i];
			if (parity[i] % 2 == 1) sum = total[i] - sum;
		}

		if (zzz != 0 && (zzz == vranges.size() - 1 || vranges[zzz+1].f > vranges[zzz].f)) {
			int yyy = zzz;
			while (vranges[yyy].f == vranges[zzz].f) yyy--;
			blackTotal += (vranges[zzz].f - vranges[yyy].f) * allSum;
		}

		pii y = vranges[zzz].s;
		print("CALC", y);
		// update
		for (int i = 0; i < len; ++i) {
			if (y.f <= data[i * len].f && data[min((i + 1) * len, (int) data.size()) - 1].s <= y.s) {
				// whole block update
				parity[i] += 1;
			} else if ((y.f <= data[i * len].f) || (data[min((i+1) * len, (int) data.size()) - 1].s <= y.s)) {
				// somewhat block update
				for (int j = i * len; j < min((i + 1) * len, (int) data.size()); ++j) {
					colors[j] = (colors[j] + parity[i]) % 2;
				}
				parity[i] = 0;

				for (int j = i * len; j < min((i + 1) * len, (int) data.size()); ++j) {
					if (y.f <= data[j].f && data[j].s <= y.s) 
						colors[j] = (colors[j] + 1) % 2;
				}

				blackCount[i] = 0;
				for (int j = i * len; j < min((i + 1) * len, (int) data.size()); ++j) {
					blackCount[i] += colors[j] * (data[j].s - data[j].f);
				}
			}
		}
	}

	print(blackTotal);
}
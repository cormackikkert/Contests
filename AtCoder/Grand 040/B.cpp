#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;
using pii = pair<int, int>;

template<class T> struct MinSeg { 
	const T ID = LLONG_MAX; // comb(ID,b) must equal b
	T combine(T a, T b) { return min(a, b);} 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID);}

	void update(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) seg[p] = combine(seg[2*p], seg[2*p+1]);
	}

	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = combine(ra,seg[l++]);
			if (r&1) rb = combine(seg[--r],rb);
		}
		return combine(ra,rb);
	}
};

template<class T> struct MaxSeg { 
	const T ID = LLONG_MIN; // comb(ID,b) must equal b
	T combine(T a, T b) { return max(a, b);} 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID);}

	void update(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) seg[p] = combine(seg[2*p], seg[2*p+1]);
	}

	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = combine(ra,seg[l++]);
			if (r&1) rb = combine(seg[--r],rb);
		}
		return combine(ra,rb);
	}
};



int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    MinSeg<ll> minSeg; minSeg.init(N);
    MaxSeg<ll> maxSeg; maxSeg.init(N);   
    
    vector<pii> args (N);
    for (int i = 0; i < N; ++i) {
        ll L, R; cin >> L >> R; args[i] = {L, R};
    }

    sort(args.begin(), args.end(), [] (pii& lhs, pii& rhs) {
        return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second);
    });
    
    for (int i = 0; i < N; ++i) {
        minSeg.update(i, args[i].second);
        maxSeg.update(i, args[i].first);
    }

    ll best = 0;

    for (int i = 1; i < N; ++i) {
        ll LHS = max(0LL, minSeg.query(0, i - 1) - maxSeg.query(0, i - 1) + 1);
        ll RHS = max(0LL, minSeg.query(i, N-1) - maxSeg.query(i, N-1) + 1);
        best = max(best, LHS + RHS);
    }

    cout << best << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;

const int n = (1 << 20);

int seg [2 * n];

void update(int p, int value) {	// set value at position p
	seg[p += n] = value;
	for (p /= 2; p; p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
}

int query(int l, int r) {	 // sum on interval [l, r]
	int ra = 0, rb = 0; 
	for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
		if (l&1) ra = ra + seg[l++];
		if (r&1) rb = seg[--r] + rb;
	}
	return ra + rb;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, Q; cin >> N >> Q;

	F0R(i, 1e6+10) seg[i] = 0;

	F0R(i, N) {
		int p; cin >> p;
		update(p, seg[n+p] + 1);
	}

	F0R(i, Q) {
		int pos; cin >> pos;
		if (pos < 0) {
			pos = -pos;
			int i = 1;
			while (2*i <= 2*n) {
				if (seg[2*i] >= pos) {
					i = 2*i;
				} else {
					pos -= seg[2*i];
					i = 2*i+1;
				}
			}
			update(i-n, seg[i] - 1);
		} else {
			update(pos,seg[pos+n] + 1);
		}
	}
	int pos = -1;
	F0R(i, 1e6+10) if (query(i, i) != 0) pos = i;
	if (pos == -1) {
		cout << 0 << endl;
	} else {
		cout << pos << endl;
	}	
}
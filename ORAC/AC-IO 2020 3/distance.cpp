#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define int long long

using vi = vector<int>;
using pii = pair<int, int>;


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, L; cin >> N >> L;
	vi arr (N);
	F0R(i, N) cin >> arr[i];
	set<int> tp;
	set<int> bp;
	tp.insert(-4*L); tp.insert(8*L);
	bp.insert(-4*L); bp.insert(8*L);
	int best = L + 1;

	for (int pos : arr) {
		if (pos % 2 == 0) {
			best = min(best, (*bp.lower_bound(pos/2) - pos/2)/2);
			best = min(best, -(*(--bp.lower_bound(pos/2)) - pos/2)/2);
			tp.insert(pos/2);
		} else {
			pos++;
			best = min(best, pos/2 - 1);
			best = min(best, (*tp.lower_bound(pos/2) - pos/2)/2);
			best = min(best, -(*(--tp.lower_bound(pos/2)) - pos/2)/2);
			bp.insert(pos/2);
		}


		if (best >= L)
			cout << -1 << " ";
		else 
			cout << best << " ";
	}
	cout << endl;
}
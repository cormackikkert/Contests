#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define f first
#define s second
#define int ll

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;


ll sq(ll x) {
	return x * x;
}
void solve() {
	int R, G, B; cin >> R >> G >> B;
	vll RS (R);
	vll GS (G);
	vll BS (B);
	F0R(i, R) cin >> RS[i];
	F0R(i, G) cin >> GS[i];
	F0R(i, B) cin >> BS[i];
	sort(RS.begin(), RS.end());
	sort(GS.begin(), GS.end());
	sort(BS.begin(), BS.end());
	ll best = INF;
	for (pair<vll, pair<vll, vll>> t : vector<pair<vll, pair<vll, vll>>> {{RS, {GS, BS}}, {RS, {BS, GS}}, {GS, {RS, BS}}, {GS, {BS, RS}}, {BS, {RS, GS}}, {BS, {GS, RS}}}) {
		vll l = t.f;
		vll m = t.s.f;
		vll h = t.s.s;
		
		int hIndex = 0;
		int mIndex = 0;
		for (ll lItem : l) {
			while (hIndex < h.size() && h[hIndex] < lItem) ++hIndex;
			if (hIndex == h.size()) break;
			ll hItem = h[hIndex];
			while (mIndex + 1 < m.size() && (
				sq(m[mIndex+1] - lItem) + sq(m[mIndex+1] - hItem) <= sq(m[mIndex] - lItem) + sq(m[mIndex] - hItem))) {
					 ++mIndex;
				}
			best = min(best, sq(m[mIndex] - lItem) + sq(m[mIndex] - hItem) + sq(lItem - hItem));
		}
	}
	cout << best << endl;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	F0R(i, T) solve();
}
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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, K; cin >> N >> K; --K;
	
	vll arr (N);
	F0R(i, N) cin >> arr[i];

	if (N == 1) {
		if (K % 2 == 0) {
			cout << arr[0];
		}
		return 0;
	}
	vll next (N);
	map<ll, ll> leftmost;
	R0F(i, N) leftmost[arr[i]] = i;
	map<ll, ll> temp;
	R0F(i, N) {
		if (temp.find(arr[i]) == temp.end()) {
			next[i] = leftmost[arr[i]];
		} else {
			next[i] = temp[arr[i]];
		}
		temp[arr[i]] = i;
	}

	vll its (N, -1);
	ll cur = 0;
	its[0] = 0;
	ll pos = 0;
	while (K) {
		if ((next[pos] == pos && (next[pos] == N -1))) {
			K -= 2;
			cur += 2;
		} else if ((next[pos] <= pos) || (next[pos] == N - 1)) {
			--K;
			++cur;
		}
		pos = (next[pos] + 1) % N;
		if (its[pos] != -1) break;
		its[pos] = cur;
	}
	
	if (K < 0) {
		cout << endl; return 0;
	} else if (K != 0) {
		ll loops = cur - its[pos];
		K %= loops;
	}

	while (K) {
		if ((next[pos] == pos && (next[pos] == N -1))) {
			K -= 2;
			cur += 2;
		} else if ((next[pos] <= pos) || (next[pos] == N - 1)) {
			--K;
		}
		pos = (next[pos] + 1) % N;
	}

	while ((pos < N) && (next[pos] > pos)) pos = next[pos] + 1;
	vll ans;
	while (pos < N) {
		ans.push_back(arr[pos]); 
		++pos;
		while ((pos < N) && (next[pos] > pos)) pos = next[pos] + 1;
	}
	
	for (ll x : ans) cout << x << " ";
	cout << endl;
}
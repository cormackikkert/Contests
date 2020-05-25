#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll INF = LLONG_MAX;

ll V;

ll check(ll s1) {
	ll other = V / s1;
	ll best = max((ll) sqrt(other), 1LL);
	while (true) {
		if (other % best == 0) {
			ll s2 = best;
			ll s3 = other / s2;
			return 2 * s1 * s2 + 2 * s2 * s3 + 2 * s1 * s3;
		}
		++best;
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> V;
	ll best = INF;
	for (ll x = 1; x * x * x <= V; ++x) if (V % x == 0) {
		best = min(best, check(x));
		// cout << "START" << endl;
		// cout << check(x) << " " << x << " " << V/x << endl;
		// best = min(best, check(V/x));
	}
	cout << best << endl;
}
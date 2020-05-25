#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

ll fac[2*(int)10e5 + 1];

ll powm(ll base, ll exp) {
	if (exp <= 0) return 1;
	if (base <= 0) return 0;
	ll val = powm(base, exp / 2);
	val = (val * val) % MOD;
	if (exp % 2 == 1) {
		val *= base;
		val %= MOD;
	}
	return val;
}


ll modInverse(ll a) {
	return powm(a, MOD - 2);
}

ll choose(ll n, ll k) {
	// cout << "CHOOSE " << n << " " << k << fac[n] << " " << modInverse(fac[k]) << " " << modInverse(fac[n - k]) <<endl;   
	return ((fac[n] * modInverse(fac[k]) % MOD) * modInverse(fac[n - k])) % MOD;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	ll n, k;
	cin >> n >> k;
	vector<int> ans(n);

	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = (i * fac[i - 1]) % MOD;
	

	for (int i = 0; i < n; ++i) {
		cin >> ans[i];
	}

	// count ways to get 0
	int total = 0;
	for (ll i = 0; i < n; ++i)
		if (ans[i] != ans[(i + 1) % n])
			++total;
	
	ll getZero = 0;
	for (int p = 0; p <= total; p += 2) {
		ll ways = choose(total, p);
		ways *= choose(p, p/2); ways %= MOD;
		ways *= powm(k - 2, total - p); ways %= MOD;
		ways *= powm(k, n - total); ways %= MOD;
		getZero = (getZero + ways) % MOD;
	}
	cout << ((powm(k, n) - getZero + MOD) * modInverse(2)) % MOD << endl;
}
vll fact (MAXN);
vll invfact (MAXN);
vll pow2(MAXN);
vll inv (MAXN);

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        res %= MOD;
        a = a * a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}

ll inverse(ll n) {
    return binpow(n, MOD-2);
}

ll choose(ll n, ll k) {
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int main() {
    fact[0] = 1;
    FOR(i, 1, N+1) fact[i] = fact[i-1] * i % MOD;

    inv[1] = 1;
    FOR(i, 2, MAXN) inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;

    invfact[0] = 1;
    FOR(i, 1, N+1) invfact[i] = invfact[i-1] * inv[i] % MOD;

    pow2[0] = 1;
    FOR(i, 1, N+1) pow2[i] = 2 * pow2[i-1] % MOD;
}

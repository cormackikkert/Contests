#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<ll>;

vi tree;

void modify(ll i, ll v) {
    i += tree.size()/2;
    tree[i] = v;
    for (i /= 2; i >= 1; i /= 2) tree[i] = tree[2*i] + tree[2*i+1];
}

ll query(ll a, ll b) {
    a += tree.size() / 2; b += tree.size() / 2;
    ll s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += tree[a++];
        if (b % 2 == 0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

vi XS, HS;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N, D, A; cin >> N >> D >> A;

    tree.resize(2 * N);
    XS.resize(N);
    HS.resize(N);

    vi perm (N);

    F0R(i, N) {cin >> XS[i] >> HS[i]; perm[i] = i;}

    sort(perm.begin(), perm.end(), [] (const ll& lhs, const ll& rhs) {
        return XS[lhs] < XS[rhs];
    });

    ll previous = 0;
    F0R(i, N) {
        
        ll p = perm[i];
        modify(i, HS[p] - previous);
        previous = HS[p];
    }

    // cout << "BEFORE: " << query(0, 0) << " " << query(0, 1) << " " << query(0, 2) << endl;
    
    ll count = 0;
    F0R(i, N) {
        ll p = perm[i];
        if (query(0, i) <= 0) continue;
        
        ll l = 0;
        ll h = N - 1;
        while (l < h) {
            ll m = l + (h - l + 1) / 2;
            // cout << "BIN: " << l << " " << m << " " << h << endl;
            if (XS[perm[m]] > XS[p] + 2 * D) {
                h = m - 1;
            } else {
                l = m;
            }
        }

        ll uses = query(0, i) / A + (query(0, i) % A != 0);
        count += uses;
        modify(i, query(i, i) - uses * A);
        if (l + 1 < N) modify(l+1, query(l+1, l+1) + uses * A);
        // cout << i << " " << uses << " " << l << endl;
        // cout << query(0, 0) << " " << query(0, 1) << " " << query(0, 2) << endl;
    }

    cout << count << endl;
}
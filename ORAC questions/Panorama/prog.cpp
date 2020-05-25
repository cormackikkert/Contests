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
using vll = vector<ll>;

vll tree;

void modify(int i, ll v) {
    i += tree.size()/2;
    tree[i] = v;
    for (i /= 2; i >= 1; i /= 2) tree[i] = max(tree[2*i], tree[2*i+1]);
}

ll query(int a, int b) {
    a += tree.size() / 2; b += tree.size() / 2;
    ll s = tree[a];
    while (a <= b) {
        if (a % 2 == 1) s = max(s, tree[a++]);
        if (b % 2 == 0) s = max(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, K; cin >> N >> K;

    tree.resize(2*(N+1));
    
    ll sum = 0;
    modify(0, 0);
    F0R(i, N) {int res; cin >> res; sum += res; modify(i+1, sum);}

    ll best = -INF;
    F0R(i, N) {
        best = max(best, query(i+1, min(N, i+K)) - query(i, i));
    }
    cout << best << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using bk = tuple<ll, int, int, int, int>;

ll INF = 1LL << 60;

int find(int p, int k) {
    return p / (2 * k) * k + min(k, p % (2 * k));
}

ll count1d(int x, int w, int k) {
    return find(x + w, k) - find(x, k);
}

ll count2d(int x, int y, int w, int h, int k) {
    ll r = count1d(x, w, k); 
    ll c = count1d(y, h, k);
    return r * c + (w-r) * (h-c);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N, K;
    ll A;
    cin >> N >> K;
    A = 1LL*N*N;
    
    vector<bk> blocks (K);
    F0R(i, K) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        w-=x; h-=y;
        --x; --y; ++w; ++h;
        blocks[i] = make_tuple(1LL*w*h, y, x, h, w);
    }

    ll best = INF;

    ROF(i, 1, N) {
        if (N % i != 0) continue;

        ll c = count2d(0, 0, N, N, i);

        for (bk block : blocks) {
            int x, y, w, h; ll a;
            tie(a, x, y, w, h) = block;    
            ll overlap = count2d(x, y, w, h, i);
            c -= overlap;
            c += a - overlap;
        }

        best = min(best, c);
        best = min(best, A-c);
    }
    
    cout << best << endl;
}
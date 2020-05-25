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

int K;
vi arr;

ll rem (ll start) {
    for (int item : arr) {
        start = start / item * 1LL* item;
    }
    return start;
}

ll find(int end) {
    ll lo = 0;
    ll hi = 1e15;
    while (lo < hi) { 
        ll mid = lo + (hi - lo + 1) / 2;
        if (rem(mid) <= end)
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> K;
    arr.resize(K);
    F0R(i, K) cin >> arr[i];
    ll l = find(1) + 1;
    ll h = find(2);
    if (rem(h) == 2) {
        cout << l << " " << h << endl;
    } else {
        cout << -1 << endl;
    }
}
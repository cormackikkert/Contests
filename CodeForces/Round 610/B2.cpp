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

template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}

void solve() {
    int N, P, K; cin >> N >> P >> K;
    vi cost (N);
    F0R(i, N) cin >> cost[i];
    sort(cost.begin(), cost.end());
    vll cumsum (N+1);
    vll skipsum (N+1);
    F0R(i, N) cumsum[i+1] = cumsum[i] + cost[i];
    F0R(i, N) {
        skipsum[i+1] = cost[i];
        if (i+1 >= K) skipsum[i+1] += skipsum[i+1-K];
    }
    //cout << "REE: " << to_string(skipsum) << endl;
    ll best = 0;
    //cout << "DATA" << endl;
    F0R(start, K) {
        int rem = P - cumsum[start];
        if (rem < 0) continue;
        ll lo = 0;
        ll hi = (N - start) / K;
        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            ll extra = skipsum[start + mid * K] - ((start == 0) ? 0 : cost[start-1]);
            if (extra <= rem) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        //cout << start << " " << lo << " " << rem << " " << skipsum[start + lo * K] << endl;
        best = max(best, lo * K + start);
    }
    cout << best << endl;

}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    F0R(i, T) solve();
}
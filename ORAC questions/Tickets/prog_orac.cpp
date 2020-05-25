#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = 1LL << 60;
 
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

ll c1, l1, c2, l2;
ll d;
vll nums;

ll binary_search(ll num) {
    ll lo = 0;
    ll hi = d;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (nums[mid] >= num)
            hi = mid;
        else
            lo = mid + 1;

    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    freopen("ticketin.txt", "r", stdin);
    freopen("ticketout.txt", "w", stdout);
    
    cin >> c1 >> l1 >> c2 >> l2;
    cin >> d;

    nums.resize(d);
    vll dp (d+1, INF);
    F0R(i, d) cin >> nums[i];

    dp[0] = 0;
    F0R(i, d) {
        if (dp[i] == INF) continue;
        ll t1 = binary_search(nums[i] + l1);
        ll t2 = binary_search(nums[i] + l2);

        dp[t1] = min(dp[t1], dp[i] + c1);
        dp[t2] = min(dp[t2], dp[i] + c2);
    }
    cout << dp[d];
}
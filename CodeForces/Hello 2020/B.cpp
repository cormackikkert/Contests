#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef
tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    ordered_set los;
    ordered_set his;

    ll gay = 0;
    ll ans = 0;
    F0R(j, N) {
        int M; cin >> M;
        vi arr (M);
        F0R(i, M) cin >> arr[i];
        reverse(arr.begin(), arr.end());
        if (!is_sorted(arr.begin(), arr.end())) {
            ++gay;
        } else {
            int lo = arr[0];
            int hi = arr[0];
            F0R(i, M) {
                lo = min(lo, arr[i]);
                hi = max(hi, arr[i]);
            }

            

            // as LOW
            ans += his.size() - his.order_of_key({lo, his.size()+1});

            // as HI
            ans += los.order_of_key({hi, -1});
            if (lo < hi) ++ans;
            los.insert({lo, los.size()});
            his.insert({hi, his.size()});
        }
    }
    //cout << ans << " " << gay << endl;
    ans += gay * gay;
    ans += gay * (N - gay);
    ans += (N-gay) * gay;
    cout << ans  << endl;
}
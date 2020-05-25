#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> nums;

int main() {
    // Should have just done intended
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("curryin.txt", "r", stdin);
    freopen("curryout.txt", "w", stdout);
    
    nums.resize(3);
    vector<ll> count (3);
    vector<ll> perm = {0, 1, 2};
    
    cin >> nums[0] >> nums[1] >> nums[2];

    sort(perm.begin(), perm.end(), [] (const ll& lhs, const ll& rhs) {
        return nums[lhs] < nums[rhs];
    });

    if (nums[perm[0]] + nums[perm[1]] <= nums[perm[2]]) {
        count[0] = nums[perm[0]];
        count[1] = nums[perm[1]];
        count[2] = 0;
    } else {
        nums[perm[2]] -=  (nums[perm[2]] % 2 != (nums[perm[0]] + nums[perm[1]]) % 2);
        count[2] = (nums[perm[0]] + nums[perm[1]] - nums[perm[2]]) / 2;
        count[0] = nums[perm[0]] - count[2];
        count[1] = nums[perm[1]] - count[2];
    }
    vector<ll> map (3);
    
    if (perm == vector<ll> {0, 1, 2}) 
        map = vector<ll>  {1, 0, 2};

    if (perm == vector<ll> {0, 2, 1}) // dc
        map = vector<ll> {1, 2, 0};

    if (perm == vector<ll>  {1, 0, 2}) // dc
        map = vector<ll> {0, 1, 2};

    if (perm == vector<ll> {1, 2, 0}) // dc
        map = vector<ll> {2, 1, 0};

    if (perm == vector<ll> {2, 0, 1}) // dc
        map = vector<ll> {0, 2, 1};

    if (perm == vector<ll> {2, 1, 0}) // dc
        map = vector<ll> {2, 0, 1};
    
    cout << count[map[0]] << " " << count[map[1]] << " " << count[map[2]] << endl;
}
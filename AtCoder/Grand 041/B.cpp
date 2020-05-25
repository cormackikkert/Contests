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

ll N, M, V, P; 
vll arr;

bool canAppear(ll index) {
    //cout << "DECIDING: " << arr[index] << endl;
    vll newArr;
    ll highest = arr[index] + M;

    ll judgeVotes = V - 1;
    
    ll bigger = 0;
    F0R(i, N) {
        if (i == index) continue;
        if (arr[i] > highest) {
            --judgeVotes;
            ++bigger;
            continue;
        }
        newArr.push_back(arr[i]);
    }
    

    ll remaining = M * judgeVotes;
    //cout << remaining << endl;
    vll probVotes (newArr.size());
    F0R(i, newArr.size()) {
        ll diff = highest - newArr[i];
        ll use = min(diff, M);
        probVotes[i] = use;
        remaining -= use;
        //cout << "USING: " << newArr[i] << " " << use << endl;
    }
    //cout << bigger << " " << remaining << endl;
    for (ll i = 0; i < newArr.size() && remaining > 0; ++i) {
        remaining -= M - probVotes[i];
        ++bigger;
    }
    return bigger < P;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> V >> P;
    arr.resize(N);
    F0R(i, N) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<ll>());
    ll lo = 0;
    ll hi = N-1;
    while (lo < hi) {
        ll mid = lo + (hi - lo+1) / 2;
        if (canAppear(mid)) 
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << lo + 1 << endl;
}
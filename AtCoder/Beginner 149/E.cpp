#include <bits/stdc++.h>
using namespace std;

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

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

ll N, M;
vll arr;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    arr.resize(N);
    F0R(i, N) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<ll>());

    ll total = 0;

    set<pii> seen;
    map<int, int> count;
    priority_queue<pair<ll, pii>> q;
    q.push({arr[0] + arr[0], {0, 0}});
    F0R(i, M) {
        while (seen.find(q.top().second) != seen.end()) q.pop();
        total += q.top().first;
        
        seen.insert(q.top().second);
        // seen.insert({q.top().second.second, q.top().second.first});

        int i1 = q.top().second.first;
        int i2 = q.top().second.second;
        cout << "DO: " << q.top().second.first << " " << q.top().second.second << endl;
        //count[arr[i1] + arr[i2]] += 1;
        if (i2 + 1 < N) q.push({arr[i1] + arr[i2+1], {i1, i2+1}});
        if (i1 + 1 < N) q.push({arr[i1+1] + arr[i2], {i1+1, i2}});
        if (i1 + 1 < N && i2 + 1 < N) q.push({arr[i1+1] + arr[i2+1], {i1+1, i2+1}});
    }
    cout << to_string(arr) << endl;
    for (auto x : count) {
        cout << arr[x.first] << " " << x.second << endl;
    }
    cout << total << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define popcount __builtin_popcountll

const ll INF = 1LL<<60;
const ll MOD = 998244353;

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
}

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

template <typename A>
string to_string(A x[], signed n) {
    string result = "{";
    for (signed i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

ll getSum(int a, int b, vector<int> arr) {
    if (a == 0)
        return arr[b];
    return arr[b] - arr[a-1];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < N; ++i) arr[i] = (arr[i] - 1 + K) % K;

    vector<int> pref(N);
    ll t = 0;
    for (int i = 0; i < N; ++i) {
        t = (t + arr[i]) % K;
        pref[i] = t;
    }

    map<int, int> count;

    int total = 0;
    for (int i = N - 1; i >= 0; --i) {
        int req = (i != 0) ? pref[i-1] : 0;
        ++count[pref[i]];
        if (i + K - 1 < N) --count[pref[i + K - 1]];
        total += count[req];
        
    }

    cout << ((K == 1) ? 0 : total) << endl;
}
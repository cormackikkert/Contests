#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define REP(i, l, r) for (int i = (l); i != (r); (l)<(r)?++i:--i)
#define popcount __builtin_popcountll
 
const ll INF = 1LL<<60;
const int MOD = 1000000007;
 
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
string to_string(A x[], int n) {
    string result = "{";
    REP(i, 0, n) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}
 
string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    REP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}
 
vector<int> getZ(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    REP(i, 1, n) {
        z[i] = max(0, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i;
            y = i+z[i];
            ++z[i];
        }
    }
    return z;
}
 
 
int powa(int base, int exp) {
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp>>1);
    val = val*val % MOD;
    if (exp&1) {
        val = val*base % MOD;
    }
    return val;
}


int N, K;
vector<int> weights;
vector<vector<int>> graph;

void getDist(vector<int> &dists, int s, int p, int c) {
    dists[s] = c;
    for (int n : graph[s]) {
        if (n == p) continue;
        getDist(dists, n, s, c + 1);
    }
}

int diam(int a, int b) {
    if (a == b) return weights[a];
    vector<int> d1 (N); getDist(d1, a, -1, 0);
    vector<int> d2 (N); getDist(d2, b, -1, 0);
    int diam = d1[b];
    cout << "DATA" << endl;
    cout << a << " " << b << endl;
    cout << to_string(d1) << endl;
    cout << to_string(d2) << endl;
    if (diam > K) return -1;
    int t = 0;
    for (int i = 0; i < N; ++i) {
        if (max(d1[i], d2[i]) <= diam && max(d1[i], d2[i]) <= K) t += weights[i];
    }
    cout << "DIAM: " << a << " " << b << " " << t << endl;
    return t;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    weights.resize(N);
    for (int i = 0; i < N; ++i) cin >> weights[i];
    graph.resize(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < N; ++i) {
        cout << i << " " << to_string(graph[i]) << endl;
    }
    int best = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            best = max(diam(i, j), best);
        }
    }
    cout << best;
}
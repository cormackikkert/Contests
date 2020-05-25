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
using vb = vector<bool>;

pair<int, int> ask(vi& arr) {
    cout << "? ";
    for (int item : arr) cout << item + 1 << " ";
    fflush(stdout);
    int pos, val; cin >> pos >> val;
    return {pos - 1, val};
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, K; cin >> N >> K;
    vi query (K);
    vb parity (K);
    
    F0R(i, K) query[i] = i;
    pair<int, int> orig = ask(query);
    F0R(skip, K) {
        if (skip == orig.first) continue;
        F0R(i, K+1) {
            if (i == skip) continue;
            query[i - (i > skip)] = i;    
        }
        pair<int, int> res = ask(query);
        if (res.first == orig.first) parity[skip] = true; 
    }
    F0R(i, K+1) {
        if (i == orig.first) continue;
        query[i - (i > orig.first)] = i;
    }
    pair<int, int> res = ask(query);

    int LT = 0;
    F0R(i, K) {
        if (i == orig.first) continue;
        if (res.second > orig.second != parity[i]) ++LT;
    }
    cout << endl;
    
    cout << "! " << LT  + 1 << endl;
    fflush(stdout);
}
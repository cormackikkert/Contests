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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    vector<string> S (N);
    
    map<char, int> occ;
    for (char c : "abcdefghijklmnopqrstuvwxyz") occ[c] = 100;

    F0R(i, N) {
        string t; cin >> t;
        map<char, int> temp;
        for (char c : t) ++temp[c];
        for (auto x : occ) occ[x.first] = min(temp[x.first], x.second);
    }

    string ans;
    for (auto x : occ) ans += string (x.second, x.first);
    cout << ans;
}
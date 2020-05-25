#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N; 
    cin >> N;
    map<string, int> all;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        all[s]++;
    }
    ll total = 0;
    for (auto const &p: all) {
        ll val = p.second;
        total += val * (val - 1) / 2;
    }
    cout << total << "\n";
}
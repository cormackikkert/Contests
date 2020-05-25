#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin >> s;
    cout << (((s[0] == s[s.size()-1]) != (s.size() % 2)) ? "First" : "Second") << endl;
}
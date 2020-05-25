#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin >> s;

    ll total = 0;

    char last = s[0];
    vi segs;
    ll curSize = 0;
    for (char c : s) {
        if (c == last) {
            curSize += 1;
        } else {
            segs.push_back(curSize);
            curSize = 1;
        }
        last = c;
    }
    segs.push_back(curSize);

    char parity = s[0];
    ll peak = 0;
    for (ll seg : segs) {
        if (parity == '<') {
            peak = seg;
            parity = '>';
        } else {
            total += max(peak, seg);
            parity = '<';
        }
        total += seg * (seg - 1) / 2;
    }
    if (s[s.size()-1] == '<') total += peak;
    cout << total  << endl;
}
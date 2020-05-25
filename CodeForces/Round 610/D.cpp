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
    cout << "a" << endl;
    fflush(stdout);
    ll la; cin >> la;
    if (la == 0) return 0;
    if (la == 300) {cout << string(300, 'b') << endl; fflush(stdout); return 0;}

    cout << string (la + 1, 'a') << endl;
    fflush(stdout);
    ll cost; cin >> cost;

    if (cost == 0) return 0;
    
    if (cost == la + 1) {
        cout << string (la, 'b') << endl; fflush(stdout); return 0;
    }

    ll length = la;
    ll lastcost = cost;
    string know = "";
    F0R(i, length + 1) {
        
        cout << know + "b" + string(length - i, 'a') << endl;
        fflush(stdout);
        ll newcost; cin >> newcost;
        if (newcost < lastcost ) know += 'b';
        else know += 'a';
        if (newcost == 0) {return 0;}
        lastcost = min(newcost, lastcost);
    } 
}
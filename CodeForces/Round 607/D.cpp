#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = 1LL << 60;
 
using vc = vector<char>;
using vi = vector<int>;

void solve() {
    int r, c;
    cin >> r >> c;
    vector<vector<bool>> grid (r);
    
    vector<bool> rowTrues;
    vector<bool> colTrues;

    bool hasA = false;
    bool hasP = false;
    bool rowFull = false;

    F0R(i, r) {
        bool rowHasP = false;
        F0R(j, c) {
            char l; cin >> l;
            if (l == 'A') hasA = true;
            else {hasP = true; rowHasP = true;}
            grid[i].push_back((l == 'A'));
        }
        if (!rowHasP) rowFull = true;
        rowTrues.push_back(!rowHasP);
    }

    if (!hasA) {
        cout << "MORTAL" << endl; return;
    }

    if (!hasP) {
        cout << 0 << endl; return;
    }

    F0R(j, c) {
        bool colHasP = false;
        F0R(i, r) {
            if (!grid[i][j]) colHasP = true;
        }
        if (!colHasP) rowFull = true;
        colTrues.push_back(!colHasP);
    }

    if (rowTrues[0] || rowTrues[r-1] || colTrues[0] || colTrues[c-1]) {
        cout << 1 << endl;
        return;
    }

    if (rowFull) {
        cout << 2 << endl;
        return;
    }

    bool corner = false;
    bool edge = false;
    bool middle = false;
    F0R(i, r) {
        F0R(j, c) {
            if (!grid[i][j]) continue;
            middle = true;
            if ((i == 0 && j == 0) || (i == 0 && j == c-1) || (i == r-1 && j == 0) || (i == r-1 && j == c-1)) corner = true;
            if (i == 0 || i == r-1 || j == 0 || j == c- 1) edge = true;            
        }
    }

    if (corner) {
        cout << 2 << endl; return;
    } else if (edge) {
        cout << 3 << endl; return;
    } else if (middle) {
        cout << 4 << endl; return;
    }
    cout << "MORTAL" << endl; return;


}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    F0R(i, t) solve();
}
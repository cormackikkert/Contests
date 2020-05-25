#include <bits/stdc++.h>
using namespace std;

int sCost [400005];
int tCost [400005];
int perm [400005];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("restin.txt", "r", stdin);
    freopen("restout.txt", "w", stdout);
    
    int A, B, N;
    cin >> N >> A >> B;

    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        a = max(0, a); b = max(0, b);
        perm[i] = i; sCost[i] = a; tCost[i] = b;
    }

    sort(perm, perm+N, [] (const int& ind1, const int& ind2) {
        return sCost[ind1]-tCost[ind1] < sCost[ind2]-tCost[ind2];
    });

    int cumsumrs = 0; int cumsumls = 0;
    for (int i = 0; i < N; ++i) cumsumrs += sCost[i];

    int best = 0;
    for (int s = 0; s < N; ++s) {
        if (N-A <= s && s <= B)
            best = max(best, cumsumrs + cumsumls);
        cumsumrs -= sCost[perm[s]];
        cumsumls += tCost[perm[s]];
    }
    
    cout << best << endl;
}
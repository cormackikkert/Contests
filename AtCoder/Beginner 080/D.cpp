#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll INF = (1LL << 60);

const int maxtime = 10e5+1;
bool sTimes[30][maxtime];
bool eTimes[30][maxtime];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll N, C;
    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        ll s, t, c;
        cin >> s >> t >> c;
        --c;
        sTimes[c][s] = true;
        eTimes[c][t] = true;
    }

    for (int c = 0; c < 30; ++c) {
        for (int i = 0; i < maxtime; ++i) {
            if (sTimes[c][i] && eTimes[c][i]) {
                sTimes[c][i] = false;
                eTimes[c][i] = false;
            }
        }
    }

    int recorders = 0;
    int cur = 0;
    for (int t = 0; t < maxtime; ++t) {
        for (int c = 0; c < 30; ++c) {
            if (sTimes[c][t]) ++cur;
        }
        recorders = max(recorders, cur);
        for (int c = 0; c < 30; ++c) {
            if (eTimes[c][t]) --cur;
        }
    }
    cout << recorders;
}
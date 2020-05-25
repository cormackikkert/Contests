#include <bits/stdc++.h>
using namespace std;

vector<int> times;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
    freopen("slicein.txt", "r", stdin);
    freopen("sliceout.txt", "w", stdout);

    int N; cin >> N;
    times.resize(N);
    vector<bool> isDeveloped (N);
    vector<int> perm (N);
    for (int i = 0; i < N; ++i) {
        cin >> times[i]; perm[i] = i;
    }
    sort(perm.begin(), perm.end(), [] (const int& i1, const int& i2) {
        return times[i1] < times[i2];
    });
    int m = 1;
    int c = 1;
    for (int i : perm) {
        int onL = (i == 0) ? 1 : (isDeveloped[i-1]);
        int onR = (i == N-1) ? 1 : (isDeveloped[i+1]);
        if (onL && onR) --c;
        else if (!onL && !onR) ++c;
        m = max(m, c);
        isDeveloped[i] = true;
    }
    cout << m;

}
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int K; int X;
    cin >> K >> X;
    for (int i = -1000000; i<=1000000; ++i) {
        if (abs(i - X) < K)
            cout << i << " ";
    }
}
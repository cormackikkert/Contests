#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    freopen("savein.txt", "r", stdin);
    freopen("saveout.txt", "w", stdout);

    int N;
    cin >> N;
    int total = 0;
    int ts = 0;
    int fs;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        total += (x+2) / 5 * 5;
        if (x % 5 == 3) ++ts;
        if (x % 5 == 4) ++fs;
    }
    while (ts != fs) {
        if (ts > fs) {
            ts -= 2;
        } else {
            fs -= 3;
        }
        total -= 5;
    }
    total -= 5 * ts;
    cout << total << endl;

}
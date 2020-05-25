#include <bits/stdc++.h>
using namespace std;

bool cool(int x) {
    int s = 0;
    while (x != 0) {
        s += x % 10;
        x /= 10;
    }
    return s % 4 == 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
    int a; cin >> a;
    while (true) {
        if (cool(a)) {
            cout << a; return 0;
        }
        ++a;
    }
}
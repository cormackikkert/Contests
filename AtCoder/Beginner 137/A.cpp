#include <bits/stdc++.h>
using namespace std;

int maxp(int a) {return a;}
template<typename... Args>
int maxp(int a, Args... args) {return max(a, maxp(args...));}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int A; int B;
    cin >> A >> B;
    cout << maxp(A * B, A + B, A - B);
}
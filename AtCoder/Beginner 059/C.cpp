#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;

int N;
vi arr;

ll calc(bool isPos) {
    int curSum = 0;
    ll curMoves = 0;
    F0R(i, N) {
        if (isPos) {
            curMoves += (arr[i] > -curSum) ? 0 : 1 - curSum - arr[i];
            curSum = (arr[i] > -curSum) ? (curSum + arr[i]) : 1; 
        } else {
            curMoves += (-arr[i] > curSum) ? 0 : curSum + 1 + arr[i];
            curSum = (-arr[i] > curSum) ? (curSum + arr[i]) : -1;
        }
        isPos = !isPos;
    }
    return curMoves;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N; arr.resize(N);
    F0R(i, N) cin >> arr[i];
    cout << min(calc(true), calc(false)) << endl;
}
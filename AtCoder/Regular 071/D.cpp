#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;

ll INF = LLONG_MAX;
ll MOD = 1e9 + 7;

using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;

int main() {
    // lol wasnt expecting this to work
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N, M; cin >> N >> M;
    vll XS (N);
    vll YS (M);    
    F0R(i, N) cin >> XS[i];
    F0R(i, M) cin >> YS[i];
    sort(XS.begin(), XS.end());
    sort(YS.begin(), YS.end());
    
    vll cumsumX (N); cumsumX[N-1] = XS[N-1];
    vll cumsumY (M); cumsumY[M-1] = YS[M-1];

    R0F(i, N-1) cumsumX[i] = cumsumX[i+1] + XS[i];
    R0F(i, M-1) cumsumY[i] = cumsumY[i+1] + YS[i];

    ll allX = 0;
    F0R(i, N - 1) allX += cumsumX[i+1] - (N - 1 - i) * XS[i], allX %= MOD;
    ld EX = allX / (N * (N-1) / 2);

    ll allY = 0;
    F0R(i, M - 1) allY += cumsumY[i+1] - (M - 1 - i) * YS[i], allY %= MOD;
    ld EY = allY / (M * (M-1) / 2);

    cout << allX * allY % MOD << endl;
    /*
    cout << allX << " " << allY << " " << allX * allY % MOD << endl;
    cout << EX << " " << EY << endl;
    cout << EX * EY * N * (N - 1) * M * (M - 1) / 4 << endl;
    */
}
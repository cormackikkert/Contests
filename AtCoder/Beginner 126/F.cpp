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
    using vll = vector<ll>;

    int main() {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        ll M, K; cin >> M >> K;
        if (K >= pow(2, M) || (M == 1 && K == 1)) {
            cout << -1 << endl;
            return 0;
        }
        if (M == 1 && K == 0) {
            cout << "0 1 1 0" << endl;
            return 0;
        }
        vll arr;
        F0R(i, pow(2, M)) if (i != K) arr.push_back(i);
        cout << K << " ";
        F0R(i, arr.size()) cout << arr[i] << " ";
        cout << K << " ";
        R0F(i, arr.size()) cout << arr[i] << " ";
        cout << endl;

    }
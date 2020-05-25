    #include <bits/stdc++.h>
    using namespace std;

    #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
    #define F0R(i,a) FOR(i,0,a)
    #define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
    #define R0F(i,a) ROF(i,0,a)

    using ll = long long;
    ll INF = 1LL << 60;
    
    using vc = vector<char>;
    using vi = vector<int>;

    void solve() {
        int n, k, d; cin >> n >> k >> d;
        unordered_map<int, int> occ;
        vi arr (n);
        F0R(i, n) cin >> arr[i];

        int types = 0;
        F0R(i, d) {
            if (occ[arr[i]] == 0) ++types;
            ++occ[arr[i]];
        }
        int best = types;

        int lo = 0, hi = d;
        for (; hi < n; ++lo, ++hi) {
            best = min(best, types);
            --occ[arr[lo]];
            if (occ[arr[lo]] == 0) --types;
            if (occ[arr[hi]] == 0) ++types;
            ++occ[arr[hi]   ];
            best = min(best, types);

        }
        
        cout << best << endl;
    }
    int main() {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int t; cin >> t;
        F0R(i, t) solve();
    }
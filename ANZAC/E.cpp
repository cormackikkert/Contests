#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define vi vector<int>
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
long long INF = 1LL<<60;
long long MOD = 1e9+7;
namespace output {
    void pr(short x) { cout << x; }
    void pr(signed x) { cout << x; }
    void pr(long x) { cout << x; }
    void pr(long long x) { cout << x; }
    void pr(unsigned short x) { cout << x; }
    void pr(unsigned x) { cout << x; }
    void pr(unsigned long x) { cout << x; }
    void pr(unsigned long long x) { cout << x; }
    void pr(float x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(long double x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(bool x) { cout << x; }
    template<size_t sz> void pr(const bitset<sz>& x) { cout << x; }
    template<class T> void pr(const complex<T>& x) { cout << x; }
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T1, class T2, class T3> void pr(const tuple<T1,T2,T3>& x);
    template<class T> void pr(const T& x);
    template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { pr("(",x.first,", ",x.second,")"); }
    template<class T1, class T2, class T3> void pr(const tuple<T1,T2,T3>& x) { pr("(",get<0>(x),", ",get<1>(x),", ",get<2>(x),")"); }
    template<class T> void pr(const T& x) { 
        pr("["); // const iterator needed for vector<bool>
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
        pr("]");
    }
    void print() { pr("\n"); } // print w/ spaces
    template<class T, class... Ts> void print(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(" "); print(ts...); }
}
using namespace output;

string nice(int bitmask) {
    if (bitmask == -1) return "-1";
    string ans = "";
    for (int i = 0; i < 9; ++i) if (((bitmask) & (1 << (9 - i - 1))) > 0) ans += to_string(i + 1);
    if (ans == "") ans = "0";
    return ans;
}

vector<vi> bitmasks (13);
vector<int> occ (13);
vector<ld> maxDP (1 << 9, -1);
ld recurseMax(int bitmask) {
    // out of use bits
    if (maxDP[bitmask] != -1) return maxDP[bitmask];
    ld ev = 0.0;
    for (int sum = 1; sum <= 12; ++sum) {
        ld best = 0.0;
        bool foundMove = false;
        for (int bm : bitmasks[sum]) if ((bm & bitmask) == 0) {
            foundMove = true;
            best = max(best, recurseMax(bitmask | bm));
        }
        if (!foundMove) {
            best = 0.0;
            string ans = "";
            for (int i = 0; i < 9; ++i) if (((~bitmask) & (1 << (9 - i - 1))) > 0) ans += to_string(i + 1);
            if (ans == "")
                best = 0.0;
            else
                best = (ld) stoi(ans);
        }
        ev += occ[sum] / 36.0 * best;
    }
    maxDP[bitmask] = ev;
    return ev;
}
vector<ld> minDP (1 << 9, -1);
ld recurseMin(int bitmask) {
    // out of use bits
    if (minDP[bitmask] != -1) return minDP[bitmask];
    ld ev = 0.0;
    for (int sum = 1; sum <= 12; ++sum) {
        ld best = INF;
        bool foundMove = false;
        for (int bm : bitmasks[sum]) if ((bm & bitmask) == 0) {
            foundMove = true;
            best = min(best, recurseMin(bitmask | bm));
        }
        if (!foundMove) {
            best = (ld) stoi (nice(~bitmask));
        }
        ev += occ[sum] / (ld) 36.0 * best;
    }
    minDP[bitmask] = ev;
    return ev;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            occ[i + j]++;
        }
    }
    for (int i = 0; i < (1 << 9); ++i) {
        int sum = 0;
        for (int j = 0; j < 9; ++j) {
            sum += (j + 1) * ((i & (1 << (9 - j - 1))) > 0);
        }
        if (sum <= 12) bitmasks[sum].push_back(i);
    }
    string rem; cin >> rem;
    int a, b; cin >> a >> b;
    int bitmask = 0;
    for (char c : rem) {
        int n = c - '0';
        bitmask |= (1 << (9 - n));
    }
    bitmask ^= (1 << 9) - 1;
    ld bmax = -1.0;
    bool foundMove = false;
    int bestMaxBitMask = -1;
    // for (int bm : bitmasks[a + b]) print(bm & bitmask);
    for (int bm : bitmasks[a + b]) if ((bm & bitmask) == 0) {
        foundMove = true;
        if (recurseMax(bitmask | bm) > bmax)
            bestMaxBitMask = bm;
        bmax = max(bmax, recurseMax(bitmask | bm));
    }
    if (!foundMove) {
        bmax = (ld) stoi (nice(~bitmask));
    }
    ld bmin = INF;
    foundMove = false;  
    int bestMinBitMask = -1;
    // for (int bm : bitmasks[a + b]) print(bm & bitmask);
    for (int bm : bitmasks[a + b]) if ((bm & bitmask) == 0) {
        foundMove = true;
        if (recurseMin(bitmask | bm) < bmin) {
            bestMinBitMask = bm;
        }
        bmin = min(bmin, recurseMin(bitmask | bm));
    }
    if (!foundMove) {
        bmin = (ld) stoi (nice(~bitmask));
    }
    cout << fixed << setprecision(5);
    cout << nice(bestMinBitMask) << " " << bmin << endl;
    cout << nice(bestMaxBitMask) << " "  << bmax << endl;
    return 0;
}
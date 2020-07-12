#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define tiiii tuple<int,int,int,int>
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 1000000007;

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
string to_string(string s) {return s;}
template <typename A, typename B>
string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) { return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";}
template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}

string bin_string(int x) {
    const int d = 32;
    string result(d, ' ');
    RREP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res*base % MOD;
        base = base*base % MOD;
        exp >>= 1;
    }
    return res;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    REP(i, 0, n) --a[i];
    vector<vi> costs(10, vi(10));
    REP(mi, 0, 10) REP(mj, 0, 10) if (mi != mj) {
        int jocc=0;
        REP(i, 0, n) {
            if (a[i]==mi) costs[mi][mj] += jocc;
            else if (a[i]==mj) ++jocc;
        }
    }

    const int BIG = 1<<10;
    vi dp(BIG, INF);
    dp[0] = 0;
    REP(mask, 0, BIG) {
        REP(nxt, 0, 10) {
            if (mask&1<<nxt) continue;
            int addcost=0;
            REP(i, 0, 10) if (mask&1<<i) addcost += costs[nxt][i];
            dp[mask|1<<nxt] = min(dp[mask|1<<nxt], dp[mask] + addcost);
        }
    }
    cout << dp[BIG-1];
}
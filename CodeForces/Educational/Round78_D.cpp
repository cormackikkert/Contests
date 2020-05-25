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
    for (int i=d-1; i>=0; --i) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}
 
vi getZ(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    REP(i, 1, n) {
        z[i] = max(0LL, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i;
            y = i+z[i];
            ++z[i];
        }
    }
    return z;
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
 
vector<vi> nodes;
vb seen;
bool failed = false;
 
int dfs(int u, int p) {
    if (seen[u]) {
        failed = true;
        return 0;
    }
    seen[u] = true;
    int res = 1;
    for (int v : nodes[u]) if (v!=p) res += dfs(v, u);
    return res;
}
 
main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n; cin >> n;
    vector<pii> segs(n);
    REP(i, 0, n) {
        int a,b;
        cin >> a >> b;
        segs[i] = {a,b};
    }
    sort(segs.begin(), segs.end());
 
    set<int> rights;
    nodes.resize(2*n+1);
    seen.resize(2*n+1);
    int res = 0;
    for (auto pr : segs) {
        int l,r; tie(l,r) = pr;
        while (!rights.empty() && *rights.begin() < l) {
            rights.erase(rights.begin());
        }
        if (!rights.empty()) {
            for (int rgt : rights) {
                if (rgt > r) break;
                ++res;
                nodes[r].push_back(rgt);
                nodes[rgt].push_back(r);
                if (res > n-1) {
                    cout << "NO";
                    return 0;
                }
            }
        }
        rights.insert(r);
    }
    if (res != n-1) cout << "NO";
    else {
        int val = dfs(segs[0].second, -1);
        if (failed || val!=n) cout << "NO";
        else cout << "YES";
    }
}
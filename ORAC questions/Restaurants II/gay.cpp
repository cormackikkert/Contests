#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (int i = (l); i != (r); (l)<(r)?++i:--i)
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 1000000007;

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
}

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

template <typename A>
string to_string(A x[], int n) {
    string result = "{";
    REP(i, 0, n) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    REP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

vector<int> getZ(string s) {
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
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp>>1);
    val = val*val % MOD;
    if (exp&1) {
        val = val*base % MOD;
    }
    return val;
}

vector<int> check(int oldarr[]) {
    int arr[4];
    REP(i, 0, 4) arr[i] = oldarr[i];
    vector<int> res;
    vector<int> empt;
    for (int i=1; i<4; ++i) {
        if (i==3 && arr[i] == arr[i-1]) {
            REP(j, 0, arr[i-1]) {
                res.push_back(i);
                res.push_back(i-1);
            }
            return res;
        }
        if (arr[i] <= arr[i-1]) {
            return empt;
        }
        REP(j, 0, arr[i-1]) {
            res.push_back(i);
            res.push_back(i-1);
        }
        res.push_back(i);
        arr[i] -= arr[i-1]+1;
        arr[i-1] = 0;
    }
    if (arr[3] == 0) return res;
    return empt;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int arr[4];
    REP(i, 0, 4) cin >> arr[i];
    REP(i, 0, 4) {
        --arr[i];
        vector<int> res = check(arr);
        if (!res.empty()) {
            cout << "YES\n";
            REP(j, i, -1) cout << j << ' ';
            for (int j : res) cout << j << ' ';
            return 0;
        }
    }
    cout << "NO";
}
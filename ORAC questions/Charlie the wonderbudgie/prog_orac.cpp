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

vi tree (2 * 500);

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

void modify(int i, int v) {
    i += tree.size()/2;
    if (v <= tree[i]) return;
    tree[i] = v;
    for (i /= 2; i >= 1; i /= 2) tree[i] = max(tree[2*i], tree[2*i+1]);
}

int query(int a, int b) {
    a += tree.size() / 2; b += tree.size() / 2;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) s = max(s, tree[a++]);
        if (b % 2 == 0) s = max(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("budgin.txt", "r", stdin);
    freopen("budgout.txt", "w", stdout);
    vi heights;
    int N = 0;
    while (true) {
        int h; cin >> h;
        heights.push_back(h);
        if (heights[N] == -1) break;
        ++N;
    }
    
    R0F(i, N) {
        modify(heights[i], 1 + query(0, heights[i]));
    } 
    cout << query(0, 499);
}
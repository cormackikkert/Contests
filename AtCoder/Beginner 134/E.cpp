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
using pii = pair<int, int>;

vector<pii> tree;

void modify(int i, pii v) {
    i += tree.size()/2;
    tree[i] = v;
    for (i /= 2; i >= 1; i /= 2) tree[i] = min(tree[2*i], tree[2*i+1]);
}

pii query(int a, int b) {
    a += tree.size() / 2; b += tree.size() / 2;
    pii s = {1e9+1,1e9+1};
    while (a <= b) {
        if (a % 2 == 1) s = min(s, tree[a++]);
        if (b % 2 == 0) s = min(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    tree.resize(2*N);
    F0R(i, N) {
        int val; cin >> val;
        modify(i, pii {val, i});
    }
    
    int operations = 0;
    while (true) {
        
        pii res = query(0, N-1);
        
        if (res.first == 1e9+1) break;
        ++operations;
        int pos = res.second + 1;
        while (pos && res.first < 1e9+1) {
            if (query(pos, pos).first <= res.first) {++pos; continue;}
            modify(pos, pii {1e9+1, 1e9+1});
            res = query(res.second + 1, N-1);
        }
        if (res.first < 1e9+1)  modify(res.second, pii {1e9+1, 1e9+1});
    }
    cout << operations << endl;
}
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
using vvi = vector<vi>;
using pbb = pair<bool, bool>;
using pii = pair<int, int>;

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

vector<bool> milkTypes;
vector<pii> treeDepth;
vi location;
vi Gdepth;
vi Hdepth;
vector<vi> graph;

vector<pii> tree;

void modify(int i, pii v) {
    i += tree.size()/2;
    tree[i] = v;
    for (i /= 2; i >= 1; i /= 2) tree[i] = min(tree[2*i], tree[2*i+1]);
}

pii query(int a, int b) {
    a += tree.size() / 2; b += tree.size() / 2;
    pii s = tree[a];
    while (a <= b) {
        if (a % 2 == 1) s = min(s, tree[a++]);
        if (b % 2 == 0) s = min(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

void dfs(int c, int p, int hd, int gd, int depth) {
    location[c] = treeDepth.size();
    treeDepth.push_back(pii {depth, c});
    if (milkTypes[c]) ++hd;
    else ++gd;

    Gdepth[c] = gd;
    Hdepth[c] = hd;

    for (int n : graph[c]) {
        if (n == p) continue;
        dfs(n, c, hd, gd, depth + 1);
        treeDepth.push_back(pii {depth, c});
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int N, M; cin >> N >> M;

    milkTypes.resize(N);
    graph.resize(N);
    location.resize(N);
    Gdepth.resize(N);
    Hdepth.resize(N);

    F0R(i, N) {
        char c; cin >> c; milkTypes[i] = (c == 'H');
    }
    F0R(i, N-1) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, -1, 0, 0, 0);
    tree.resize(2* treeDepth.size());
    F0R(i, treeDepth.size()) {
        modify(i, treeDepth[i]);
    }

    F0R(i, M) {
        int a, b; cin >> a >> b; --a; --b;
        char c; cin >> c;

        int sIndex = min(location[a], location[b]);
        int eIndex = max(location[a], location[b]);
        pii res = query(sIndex, eIndex);
        int LCA = get<1>(res);
        if (c == 'H') {
            if (milkTypes[LCA]) cout << '1';
            else if ((a == LCA && milkTypes[a]) || (b == LCA && milkTypes[b])) cout << '1';
            else if (Hdepth[a] + Hdepth[b] - 2 * Hdepth[LCA] > 0) cout << '1';
            else cout << '0';
        } else {
            if (!milkTypes[LCA]) cout << '1';
            else if ((a == LCA && !milkTypes[a]) || (b == LCA && !milkTypes[b])) cout << '1';
            else if (Gdepth[a] + Gdepth[b] - 2 * Gdepth[LCA] > 0) cout << '1';
            else cout << '0';
        }
    }
    cout << endl;
}
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

vector<vi> graph;
vi c;
bool failed = false;

vi dfs(int n) {
    vi cur;
    for (int nn : graph[n]) for (int x : dfs(nn)) cur.push_back(x);
    
    if (c[n] > cur.size()) failed = true;
    else cur.insert(cur.begin() + c[n], n);
    
    return cur;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    graph.resize(N); c.resize(N);
    int rt = -1;
    F0R(i, N) {
        int pi, ci; cin >> pi >> ci;
        c[i] = ci;
        if (pi == 0) rt = i;
        else graph[pi-1].push_back(i);
    }

    vi sorted = dfs(rt);

    if (failed) {
        cout << "NO\n"; return 0;
    }

    vi ans (N);
    F0R(i, N) ans[sorted[i]] = i;

    cout << "YES\n";
    F0R(i, N) cout << ans[i]+1 << " ";
}
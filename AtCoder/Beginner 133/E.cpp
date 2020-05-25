#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = 1LL << 60;
ll MOD = 1000000007LL;
using vc = vector<char>;
using vi = vector<int>;

vector<vi> graph;
vi mult;

int N, K;

void dfs(int cur, int par, int grands) {
    mult[cur] = K - (par != -1) - grands;
    int tot = (par != -1);
    for (int n : graph[cur]) {
        if (n != par) dfs(n, cur, tot++);
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> N >> K;
    graph.resize(N);
    mult.resize(N);

    F0R(i, N - 1) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1, 0);
    ll ans = 1;
    F0R(i, N) {
        ans *= mult[i];
        ans %= MOD;
    }
    cout << endl;
    cout << ans << endl;
    
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

int INF = 1e9;
 
using vc = vector<char>;
using vi = vector<int>;
using pii = pair<int, int>;

int N, M;
vector<vector<pii>> graph;
vi loc;

bool isValid = true;
void search(int node, int pos) {
    loc[node] = pos;
    for (pii n : graph[node]) {
        if (loc[n.first] == INF) search(n.first, pos + n.second);
        else if (loc[n.first] != pos + n.second) isValid = false;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M; graph.resize(N);
    
    F0R(i, M) {
        int a, b, d; cin >> a >> b >> d;
        --a; --b;
        graph[a].push_back({b, d});
        graph[b].push_back({a, -d});
    }

    loc = vi (N, INF);
    F0R(i, N) {
        if (loc[i] != INF) continue;
        search(i, 0);
    }
    cout << ((isValid) ? "Yes" : "No") << endl;
}

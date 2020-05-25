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

int n;
vector<vi> graph;
vi sp, ep;

void build(int cur, int par, int& pos) {
    for (int n : graph[cur]) {
        if (n != par) sp[n] = pos++;
    }
    ep[cur] = pos++;
    for (auto it = graph[cur].rbegin(); it != graph[cur].rend(); ++it)
        if (*it!= par) {build(*it, cur, pos);}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    graph.resize(n+1);
    sp.resize(n+1);
    ep.resize(n+1);
    F0R(i, n-1) {
        int a; int b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    sp[1] = 1;
    int pos = 2;
    build(1, -1, pos);
    FOR(i, 1, n+1) {
        cout << sp[i] << " " << ep[i] << endl;
    }
}
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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    vector<vi> graph (N);
    F0R(i, N-1) {
        int a; int b; cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int bc = 0;
    int wc = 0;
    vector<bool> visited (N);
    queue<pair<int, bool>> q;
    q.push({0, 1});
    q.push({N-1, 0});
    visited[0] = true;
    visited[N-1] = true;
    while (!q.empty()) {
        int node = q.front().first;
        bool col = q.front().second;
        q.pop();

        if (col) ++bc;
        else ++wc;

        visited[node] = true;

        for (int n : graph[node]) {
            if (!visited[n]) q.push({n, col}), visited[n] = true;
        }
    }
    cout << ((bc > wc)  ? "Fennec" : "Snuke") << endl;
}
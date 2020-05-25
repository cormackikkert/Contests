#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, P, B, C;
vector<vector<pair<int, int>>> graph;

bool check(int cap) {
    queue<int> q;
    q.push(B);
    bool visited[N+1] = {0};
    visited[B] = true;
    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        for (auto n : graph[pos]) {
            int neighbour, weight;
            tie(neighbour, weight) = n;
            if (weight <= cap && !visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
    return visited[C];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("catsin.txt", "r", stdin);
    freopen("catsout.txt", "w", stdout);

    cin >> N >> P;

    graph.resize(N+1);
    for (int i = 0; i < P; ++i) {
        int X, Y, K;
        cin >> X >> Y >> K;
        graph[X].push_back({Y, K});
        graph[Y].push_back({X, K});
    }
    cin >> B >> C;

    int l = 0;
    int r = 1000000;

    
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }
    
    cout << l << endl;
}
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
int N;
pair<int, int> getFurthest(int pos) {
    vector<bool> visited (N);
    queue<pair<int, int>> search;
    visited[pos] = true;
    search.push({pos, 0});
    while (true) {
        pair<int, int> cur = search.front(); search.pop();
        int curPos = cur.first;
        int curDist = cur.second;
        for (int n : graph[curPos]) {
            if (!visited[n]) {visited[n] = true; search.push({n, curDist + 1});}
        }
        if (search.empty()) return cur;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> N;
    graph.resize(N);
    F0R(i, N-1) {
        int A, B; cin >> A >> B; --A; --B; 
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    pair<int, int> ldiam = getFurthest(0);
    int diam = getFurthest(ldiam.first).second + 1;
    
    if ((diam + 1) % 3 == 0) {    
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
}
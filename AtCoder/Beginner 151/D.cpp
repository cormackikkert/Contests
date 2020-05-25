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

bool grid [20][20];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int H, W; cin >> H >> W;
    int bestDist = 0;
    F0R(y, H) {
        F0R(x, W) {
            char c; cin >> c; 
            grid[y][x] = (c == '#');
        }
    }
    F0R(y, H) {
        F0R(x, W) {
            if (grid[y][x]) continue;
            int dist [20][20];
            bool visited[20][20];
            F0R(i, 20) {
                F0R(j, 20) {
                    dist[i][j] = 0;
                    visited[i][j] = false;
                }
            }

            queue<pair<int, int>> q;
            q.push(pair<int, int> {x, y});
            visited[y][x] = true;

            while (!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();
                for (pair<int, int> delta : vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                    int nx = cur.first + delta.first;
                    int ny = cur.second + delta.second;
                    if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;\
                    if (visited[ny][nx]) continue;
                    if (grid[ny][nx]) continue;

                    q.push(pair<int, int> {nx, ny});
                    visited[ny][nx] = true;
                    dist[ny][nx] = dist[cur.second][cur.first] + 1;
                }
            }

            F0R(i, 20) {
                F0R(j, 20) {
                    bestDist = max(bestDist, dist[i][j]);
                }
            }

        }
    }
    cout << bestDist << endl;
}
#include <bits/stdc++.h>
using namespace std;
 
int INF = 100000;
char grid[100][100];
int dist[100][100];

int R, C;
int sy, sx;

pair<int, int> getDir(char c) {
    switch(c) {
        case 'L': return {-1, 0};
        case 'R': return {1, 0};
        case 'U': return {0, -1};
        case 'D': return {0, 1};
        case 'F': return {-1, -1};
    }
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("mazein.txt", "r", stdin);
    freopen("mazeout.txt", "w", stdout);

    cin >> R >> C;
    cin >> sy >> sx; --sy; --sx;

    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cin >> grid[y][x];
            dist[y][x] = INF;
        }
    }

    dist[sy][sx] = 0;
    using ds = pair<int, pair<int, int>>;
    priority_queue<ds, vector<ds>, greater<ds>> q;
    q.push({0, {sx, sy}});
    while (!q.empty()) {
        int px = q.top().second.first;
        int py = q.top().second.second;
        
        if (q.top().first != dist[py][px]) continue;
        q.pop();
        
        if (grid[py][px] == 'F') {
            cout << dist[py][px] << endl;
            return 0;
        }

        int mx = getDir(grid[py][px]).first;
        int my = getDir(grid[py][px]).second;
        
        for (int i = 1; i <= 200; ++i) {
            int nx = px + i * mx;
            int ny = py + i * my;
            if (0 <= nx && nx < C && 0 <= ny && ny < R) {
                if (grid[ny][nx] == 'X') break;
                pair<int, int> newp = getDir(grid[ny][nx]);
                if (-mx == newp.first && -my == newp.second) continue;
                if (dist[py][px] + 1 < dist[ny][nx]) {
                    dist[ny][nx] = dist[py][px] + 1;
                    q.push({dist[ny][nx], {nx, ny}});
                }
            } else {
                break;
            }
        }
    }
}
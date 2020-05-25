#include <bits/stdc++.h>
using namespace std;

int H, W, c;
vector<vector<bool>> grid (1000, vector<bool> (1000));
vector<vector<bool>> visited (1000, vector<bool> (1000));
vector<int> minRow (1000);
vector<int> maxRow (1000);

void search(int x, int y) {
    visited[y][x] = true;
    ++c;
    minRow[y] = min(minRow[y], x);
    maxRow[y] = max(maxRow[y], x);
    for (auto pv : vector<pair<int, int>> {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}) {
        int nx = x + pv.first;
        int ny = y + pv.second;
        if (0 <= nx && nx < W && 0 <= ny && ny < H && grid[ny][nx] && !visited[ny][nx]) {
            search(nx, ny);
        }
    }
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("artin.txt", "r", stdin);
    freopen("artout.txt", "w", stdout);

    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c;
            cin >> c;
            grid[i][j] = (c == 'X');
            visited[i][j] = false;
        }
    }
    int best = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (visited[i][j] || !grid[i][j]) continue;
            c = 0;
            fill(minRow.begin(), minRow.end(), W);
            fill(maxRow.begin(), maxRow.end(), -1);
            search(j, i);
            if (c - 1 <= best) continue;
            for (int c1 = 0; c1 < H; ++c1) {
                if (minRow[c1] == W) continue;
                for (int c2 = 0; c2 < H; ++c2) {
                    if (maxRow[c2] == -1) continue;
                    best = max(best, abs(maxRow[c2] - minRow[c1]) + abs(c2 - c1));
                }
            }
        }
    }
    cout << best;
}
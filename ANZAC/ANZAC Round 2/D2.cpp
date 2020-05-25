#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define t4i tuple<int,int,int,int>
#define vx vector<t4i>
#define vvx vector<vx>
#define vvvx vector<vvx>
#define vvvvx vector<vvvx>
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)

int MOD = 1e9+7;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
	
	int m, sx, sy, tx, ty;
	cin >> m >> sx >> sy >> tx >> ty;

	vi DX = {0, 0, 1, -1};
	vi DY = {1, -1, 0, 0};

	// cout << "start" << endl;
	vvvvx par(102, vvvx(102, vvx(m, vx(5, {-1, -1, -1, -1}))));
	vvvvi dist(102, vvvi(102, vvi(m, vi(5, -1))));
    vvvvi ways(102, vvvi(102, vvi(m, vi(5, 0))));
	// cout << "start2" << endl;
	queue<t4i> q;
	q.push(make_tuple(sx, sy, 0, 4));
	par[sx][sy][0][4] = {sx, sy, 0, 4};
	dist[sx][sy][0][4] = 0;
    ways[sx][sy][0][4] = 1;
	t4i done = {-1, -1, -1, -1};
	int loops = 0;
	while (!q.empty()) {
		int x, y, t, pd;
		tie(x, y, t, pd) = q.front();
		++loops;
		// cout << "checking " << x << ' ' << y << ' ' << t << ' ' << pd << endl;
		q.pop();
		
		FOR(d, 0, 4) {
			int xx = x + DX[d];
			int yy = y + DY[d];
			if (xx < sx-1 && xx < tx-1 || xx > sx+1 && xx > tx+1 || yy < sy-1 && yy < ty-1 || yy > sy+1 && yy > ty+1) continue;
            if ((dist[xx][yy][(t+1)%m][d] != -1) && (dist[x][y][t][pd] + 1 > dist[xx][yy][(t+1)%m][d])) continue;
            if (dist[xx][yy][(t+1)%m][d] == -1) {
                ways[xx][yy][(t+1)%m][d] = ways[x][y][t][pd];
            } else {
                ways[xx][yy][(t+1)%m][d] += ways[x][y][t][pd];
            }
            ways[xx][yy][(t+1)%m][d] %= MOD;
            if (dist[xx][yy][(t+1)%m][d] != -1) continue;
			if (t % m == 0 && d == pd) continue;
			q.emplace(xx, yy, (t+1)%m, d);
			par[xx][yy][(t+1)%m][d] = {x, y, t, pd};
			dist[xx][yy][(t+1)%m][d] = dist[x][y][t][pd] + 1;
			if (xx == tx && yy == ty && get<2>(done) == -1) {
				done = {xx, yy, (t+1)%m, d};
				break;
			}
		}
	}
	int x = tx, y = ty, t = get<2>(done), d = get<3>(done);
	cout << dist[x][y][t][d] << " " << ways[x][y][t][d] << endl;
}
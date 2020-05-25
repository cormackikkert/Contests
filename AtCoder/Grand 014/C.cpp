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
using vb = vector<bool>;
using pii = pair<int, int>;
using piii = tuple<int, int, int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int H, W, K; cin >> H >> W >> K;
    vector<vb> grid (H, vb (W));

    int sx, sy;
    F0R(i, H) {
        F0R(j, W) {
            char c; cin >> c;
            grid[i][j] = (c == '#');
            if (c == 'S') {sx = j; sy = i;}
        }
    }
    vector<vector<piii>> dist (H, vector<piii> (W, make_tuple(H*W+2, 0, 0)));
    dist[sy][sx] = make_tuple(1, 0, 0);

    priority_queue<pair<piii, pii>, vector<pair<piii, pii>>, greater<pair<piii, pii>>> q;
    q.push({{dist[sy][sx]}, {sx, sy}});
    while (!q.empty()) {
        piii d = q.top().first;
        pii pos = q.top().second;
        q.pop();
        
        int px, py; tie(px, py) = pos;
        

        if (d != dist[py][px]) continue;

        int d_m, d_n, d_k;
        d_m = get<0>(d); d_n = get<1>(d); d_k = get<2>(d);

        // printf("Searching: (%d, %d), (%d, %d, %d)\n", px, py, d_m, d_n, d_k);

        if (px == 0 || px == W - 1 || py == 0 || py == H - 1) {
            cout <<d_m << endl; return 0;
        }

        for (auto delta : vector<pii> {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}) {
            int dx, dy; tie(dx, dy) = delta;
            piii newDist;
            if (grid[py+dy][px+dx]) {
                if (d_k == 0) 
                    newDist = make_tuple(d_m + 1, 1, K - 1);
                else if (d_n == K) {
                    newDist = make_tuple(d_m + 1, 1, d_k + K - 1);
                } else {
                    newDist = make_tuple(d_m, 1 + d_n, d_k - 1);
                }
            } else {
                if (d_n == K) {
                    newDist = make_tuple(d_m+1, 1, d_k + K);
                } else {
                    newDist = make_tuple(d_m, 1+d_n, d_k);
                }
            }
            if (newDist < dist[py+dy][px+dx]) {
                dist[py+dy][px+dx] = newDist; 
                q.push({newDist, {px+dx, py+dy}});
            }
        }
    }
}
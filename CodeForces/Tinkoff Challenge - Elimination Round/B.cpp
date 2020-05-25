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
using vs = vector<string>;
using state = tuple<int, int, int, int>;

vi DX = {-1, 0, 1, 0};
vi DY = {0, 1, 0, -1};
bool visited [1000][1000][4][3];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M; cin >> N >> M;
    vs grid (N);
    F0R(i, N) cin >> grid[i];

    int SX = -1;
    int SY = -1;
    F0R(i, N) {
        F0R(j, M) {
            if (grid[i][j] == 'S') {
                SX = j; SY = i;
            }
        }
    }
    
    queue<state> q; 

    F0R(i, 4) q.push(make_tuple(SX, SY, i, 0));

    bool found = false;

    while (!q.empty()) {
        state pos = q.front();
        q.pop();
        int PX = get<0>(pos);
        int PY = get<1>(pos);
        
        

        int dir = get<2>(pos);
        int uses = get<3>(pos);

        if (grid[PY][PX] == 'T') {found = true;}

        //cout << "INFO : " << PX << " " << PY << " " << dir << " " << uses << endl;
        F0R(i, 4) {
            int NX = PX + DX[i];
            int NY = PY + DY[i];
            int Nuses = uses + (i != dir);
            if (0 <= NX && NX < M && 0 <= NY && NY < N && Nuses <= 2) {
                if (grid[NY][NX] == '*') continue;
                //cout << NX << " " << NY << " " << i << " " << Nuses << endl;
                state node = make_tuple(NX, NY, i, Nuses);
                if (!visited[NY][NX][i][Nuses]) {
                    visited[NY][NX][i][Nuses] = true;
                    q.push(node);
                }
            }
        }
    }
    cout << ((found) ? "YES" : "NO") << endl;
}
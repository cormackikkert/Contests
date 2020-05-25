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

vector<vc> letters = {{'a', 'b', 'c', 'd'}, {'e','f','g','h'}, {'i', 'j', 'k', 'l'}, {'m', 'n', 'o', 'p'}};

vc getLetters(int i, int j) {
    if (i % 2 == 0 && j % 2 == 0) return letters[0];
    if (i % 2 == 1 && j % 2 == 0) return letters[1];
    if (i % 2 == 0 && j % 2 == 1) return letters[2];
    if (i % 2 == 1 && j % 2 == 1) return letters[3];
}

vector<vc> draw3(int N) {
    vector<vc> grid (N, vc (N, '.'));
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            vc lets = getLetters(i, j);
            grid[i][j+2] = lets[0];
            grid[i+1][j+2] = lets[0];
            grid[i+2][j] = lets[1];
            grid[i+2][j+1] = lets[1];
        }
    }
    return grid;
}

vector<vc> draw4(int N) {
    vector<vc> grid (N, vc (N, '.'));
    for (int i = 0; i < N; i += 4) {
        for (int j = 0; j < N; j += 4) {
            vc lets = getLetters(i, j);
            grid[i][j] = lets[0];
            grid[i][j+1] = lets[0];
            grid[i+1][j] = lets[1];
            grid[i+1][j+1] = lets[1];
            grid[i][j+2] = lets[2];
            grid[i+1][j+2] = lets[2];
            grid[i][j+3] = lets[3];
            grid[i+1][j+3] = lets[3];

            grid[i+2][j] = lets[2];
            grid[i+3][j] = lets[2];
            grid[i+2][j+1] = lets[3];
            grid[i+3][j+1] = lets[3];
            grid[i+2][j+2] = lets[0];
            grid[i+2][j+3] = lets[0];
            grid[i+3][j+2] = lets[1];
            grid[i+3][j+3] = lets[1];
        }
    }
    return grid;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    vector<vc> ans;
    if (N%3 == 0) 
        ans = draw3(N);
    else if (N%4 == 0) 
        ans = draw4(N);
    else {
        cout << -1 << endl; return 0;
    }

    F0R(i, N) {
        F0R(j, N) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    
}
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

int N, K; 
bool isValid() {
    if (N == 2) return K == 0;
    return ((N-1) * (N-2)) / 2 >= K;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    if (!isValid()) {
        cout << -1 << endl; return 0;
    }
    vector<vi> graph (N);
    FOR(i, 1, N) {
        graph[i].push_back(0);
        graph[0].push_back(i);
    }
    int total = ((N-1) * (N-2)) / 2;
    for (int s = 1; s < N && total > K; ++s) {
        for (int e = s + 1; e < N && total > K; ++e) {
            graph[s].push_back(e);
            graph[e].push_back(s);
            --total;
        }
    }

    cout << N - 1 + ((N-1) * (N-2)) / 2 - K << endl;
    F0R(i, N) {
        for (int e : graph[i]) {
            if (i > e) continue;
            cout << i + 1 << " " << e + 1 << endl;
        }
    }
}
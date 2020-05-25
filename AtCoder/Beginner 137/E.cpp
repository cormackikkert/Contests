#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll INF = (1LL << 60);

template <typename A>
string to_string(A x[], signed n) {
    string result = "{";
    for (signed i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    ll N, M, P;
    cin >> N >> M >> P;

    vector<tuple<int, int, int>> edges (M);
    
    for (int i = 0; i < M; ++i) {
        ll A, B, C;
        cin >> A >> B >> C;
        tuple<int, int, int> tmp (A-1, B-1, P - C);
        edges[i] = tmp;
    }

    ll dist[N];
    for (int i = 0; i < N; ++i) dist[i] = INF;

    dist[0] = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (auto edge : edges) {
            ll s, e, c;
            tie(s, e, c) = edge;
            if (dist[s] != INF && dist[s] + c < dist[e]) {
                dist[e] = dist[s] + c;
            }
        }
    }

    // long cycles
    ll score = dist[N-1];
    
    for (int i = 0; i < M; ++i) {
        for (auto edge : edges) {
            ll s, e, c;
            tie(s, e, c) = edge;
            if (dist[s] != INF && dist[s] + c < dist[e] && e == N - 1) {
                cout << -1 << "\n";
                return 0;
            } else if (dist[s] != INF && dist[s] + c < dist[e]) {
                dist[e] = -INF;
            }
        }
    }
    cout << max(0LL, -score) << "\n";
}
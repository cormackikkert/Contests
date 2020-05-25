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

int N;
vi weights;

int dist(int a, int b) {
    return (b >= a) ? b - a : b - a + N;
}

int cost(int s, int e) {
    if (dist(s, e) <= 3) return 0;
    int best = 0;
    for (int s1 = s; s1 != e; s1 = (s1 + 1) % N) {
        for (int s2 = s1; s2 != e; s2 = (s2 + 1) % N) {
            if (dist(s1, s2) <= 1) continue;
            best = max(weights[s1] * weights[s2] + cost(s, s1) + cost(s2, e));
        }
    }
    
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    freopen("polyin.txt", "r", stdin);
    freopen("polyout.txt", "w", stdout);

    cin >> N;
    weights = vi(N);

    cout << cost(0, N-1);
}
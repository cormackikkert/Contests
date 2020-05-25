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
using pii = pair<int, int>;

int round_up(int x, int r) {
    return r * (x/r + (x % y != 0)); 
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    vi target (N);
    F0R(i, N) cin >> target[i];

    vi cur (N);
    F0R(i, N) cin >> cur[i];

    priority_queue<pair<int, int>> q;
    F0R(i, N) q.push({cur[i], i});

    int moves = 0;
    while (!q.empty()) {
        pii front = q.front();
        q.pop();

        int index = front.second;

        cout << "CONSID: " << index << endl;

        int il = (index+1)%N;
        int ir = (index-1+N)%N;

        int onSides = cur[il] + cur[ir];

        if (cur[index] == target[index] ||
            cur[index] < onSides) continue;
    
        int newPos = max(round_up(target[index], onSides), cur[index] % onSides));

        moves += (cur[index] - newPos) % onSides;
        cur[index] = newPos;

        q.push({cur[il], il});
        q.push({cur[ir], ir});

    }
    cout << moves << endl;
}
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
using segment = pair<int, pair<int, int>>;

int N, Q;
vi startTimes;
vi queryPerm;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    vector<pair<pair<int, int>, int>> segments (N);
    F0R(i, N) {
        int S, T, X;
        cin >> S >> T >> X;
        segments[i] = {{S-X, T-X-1}, X};
    }
    
    sort(segments.begin(), segments.end());

    startTimes.resize(Q);
    F0R(i, Q) {
        cin >> startTimes[i];
    }

    int curSegment = 0;
    priority_queue<segment, vector<segment>, greater<segment>> q;
    
    F0R(i, Q) {
        while (curSegment < N && segments[curSegment].first.first <= startTimes[i]) {
            q.push({segments[curSegment].second, segments[curSegment].first});
            curSegment++;
        }

        while (!q.empty() && q.top().second.second < startTimes[i]) {
            q.pop();
        }

        cout << ((q.empty()) ? -1 : q.top().first) << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll INF = (1LL << 60);
ll N, R, C;
vector<int> heights;

bool check(int diff) {
    int found = R;

    int s = 0;
    while (s + C - 1 < N) {
        if (heights[s + C - 1] - heights[s] <= diff) {
            found--;
            s += C;
        } else {
            ++s;
        }
    }
    return found <= 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> R >> C;
    heights.resize(N);
    for (int i = 0; i < N; ++i) cin >> heights[i];
    sort(heights.begin(), heights.end());

    int l = 0;
    int h = heights[N-1] - heights[0];
    
    while (l < h) {
        int mid = l + (h - l) / 2;
        if (check(mid)) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}
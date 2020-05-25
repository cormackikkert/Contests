#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("frogin.txt", "r", stdin);
    freopen("frogout.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> heights (N);
    for (int i = 0; i < N; ++i) cin >> heights[i];

    vector<int> minLeft (N);
    vector<int> minRight(N);
    
    minLeft[0] = heights[0];
    for (int i = 1; i < N; ++i) minLeft[i] = min(minLeft[i-1], heights[i]);

    minRight[N-1] = heights[N-1];
    for (int i = N-2; i >= 0; --i) minRight[i] = min(minRight[i+1], heights[i]);

    int best = 0;
    for (int i = 1; i < N-1; ++i) {
        if (heights[i] <= minLeft[i-1] or heights[i] <= minRight[i+1]) continue;
        best = max(best, 2 * heights[i] - minLeft[i-1] - minRight[i+1]);
    }
    cout << best;
}
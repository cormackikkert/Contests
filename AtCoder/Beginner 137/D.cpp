#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll INF = 1LL << 60;
ll weights [(int) 1e5 + 1];
ll rewards [(int) 1e5 + 1];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll N, M;
    cin >> N >> M;
    map<int, vector<int>> jobs;

    for (int i = 0; i < N; ++i) {
        ll t, r;
        cin >> t >> r;
        if (t > M) continue;
        jobs[t].push_back(r);
    }

    multiset<int> possibleJobs;
    ll total = 0;
    for (int t = 1; t <= M; ++t) {
        for (int x : jobs[t]) {
            possibleJobs.insert(x);
        }
        if (possibleJobs.empty()) continue;
        
        total += *(--possibleJobs.end());
        possibleJobs.erase(--possibleJobs.end());
    }
    cout << total << endl;
}
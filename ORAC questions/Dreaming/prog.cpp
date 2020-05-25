#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, L;

vector<ll> prelimMaxDist;
vector<ll> maxDist;
vector<bool> visited1;
vector<bool> visited2;
vector<bool> visited3;
vector<vector<pair<ll, ll>>> graph;

ll dfs1(ll index) {
    prelimMaxDist[index] = 0;
    visited1[index] = true;
    for (auto n : graph[index]) {
        ll neighbour, weight;
        tie(neighbour, weight) = n;
        if (visited1[neighbour]) continue;
        prelimMaxDist[index] = max(prelimMaxDist[index], dfs1(neighbour) + weight);
    }
    return prelimMaxDist[index];
}

void dfs2(ll index, ll distanceTo) {
    visited2[index] = true;
    pair<ll, ll> firstMax = {distanceTo, -1};
    pair<ll, ll> secondMax = {0, 0};
    for (auto n : graph[index]) {
        ll neighbour, weight;
        tie(neighbour, weight) = n;
        if (visited2[neighbour]) continue;

        if (prelimMaxDist[neighbour] + weight > firstMax.first) {
            secondMax = firstMax; firstMax = {prelimMaxDist[neighbour] + weight, neighbour};
        } else if (prelimMaxDist[neighbour] + weight > secondMax.first) {
            secondMax = {prelimMaxDist[neighbour] + weight, neighbour};
        }
    }
    maxDist[index] = firstMax.first;

    for (auto n : graph[index]) {
        ll neighbour, weight;
        tie(neighbour, weight) = n;
        if (visited2[neighbour]) continue;
        dfs2(neighbour, (firstMax.second != neighbour) ? firstMax.first + weight : secondMax.first + weight);
    }
}

ll dfs3(ll index) {
    visited3[index] = true;
    ll bestSpot = index;
    for (auto n : graph[index]) {
        ll neighbour, weight;
        tie(neighbour, weight) = n;
        if (visited3[neighbour]) continue;
        ll res = dfs3(neighbour);
        if (maxDist[res] < maxDist[bestSpot]) bestSpot = res;
    }
    return bestSpot;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> L;

    graph.resize(N); prelimMaxDist.resize(N); maxDist.resize(N); visited1.resize(N); visited2.resize(N); visited3.resize(N); 
    fill(visited1.begin(), visited1.end(), false); fill(visited2.begin(), visited2.end(), false);  fill(visited3.begin(), visited3.end(), false);
    fill(prelimMaxDist.begin(), prelimMaxDist.end(), 0);
    fill(maxDist.begin(), maxDist.end(), 0);
    
    for (ll i = 0; i < M; ++i) {
        ll A, B, T;
        cin >> A >> B >> T;
        graph[A].push_back({B, T});
        graph[B].push_back({A, T});
    }

    vector<ll> components;

    for (ll i = 0; i < N; ++i) {
        if (visited1[i]) continue;
        dfs1(i);
        dfs2(i, 0);
        ll best = dfs3(i);
        components.push_back(maxDist[best]);
    }

    
    ll most = 0;
    for (ll i = 0; i < N; ++i) most = max(most, maxDist[i]);

    sort(components.begin(), components.end(), greater<ll>());
    if (components.size() > 1) {
        most = max(most, components[0] + components[1] + L);
    }
    if (components.size() > 2) {
        most = max(most, components[1] + components[2] + 2 * L);
    }
    cout << most;
}
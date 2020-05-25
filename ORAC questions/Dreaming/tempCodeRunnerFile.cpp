#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}

ll INF = 1LL << 60;
ll N, M, L;
ll c, t;

vector<ll> prelimMaxDist;
vector<ll> maxDist;
vector<bool> visited1;
vector<bool> visited2;
vector<bool> visited3;
vector<vector<pair<ll, ll>>> graph;

ll dfs1(ll index) {
    prelimMaxDist[index] = 0;
    visited1[index] = true;
    ++c;
    for (auto n : graph[index]) {
        ll neighbour, weight;
        tie(neighbour, weight) = n;
        if (visited1[neighbour]) continue;
        t += weight;
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
    freopen("two-sticks-0.in", "r", stdin);
    cin >> N >> M >> L;

    graph.resize(N); prelimMaxDist.resize(N); maxDist.resize(N); visited1.resize(N); visited2.resize(N); visited3.resize(N); 
    fill(visited1.begin(), visited1.end(), false); fill(visited2.begin(), visited2.end(), false);  fill(visited3.begin(), visited3.end(), false);

    for (ll i = 0; i < M; ++i) {
        ll A, B, T;
        cin >> A >> B >> T;
        graph[A].push_back({B, T});
        graph[B].push_back({A, T});
    }

    vector<ll> components;

    for (ll i = 2; i < N; ++i) {
        if (visited1[i]) continue;
        
        c = 0, t = 0;
        dfs1(i);
        dfs2(i, 0);
        cout << "Found at " << i << " " << c << " " << t << endl;
        ll best = dfs3(i);
        components.push_back(maxDist[best]);
    }

    

    sort(components.begin(), components.end(), greater<ll>());

    cout << to_string(components) << endl;
    ll most = components[0] + components[1] + L;
    if (components.size() > 2) {
        most = max(most, components[1] + components[2] + 2 * L);
    }
    cout << most;
}
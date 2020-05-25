#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = 1LL << 60;
 
using vc = vector<char>;
using vi = vector<ll>;

struct DsjSet {
    vi parent;

    DsjSet(ll x) {
        parent.resize(x);
    }

    void make_set(ll v) {
        parent[v] = v;
    }

    ll find_set(ll v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[a] = b;
    }
};

struct Edge {
    ll u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};



int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll N, M;
    cin >> N >> M;
    vi cities (N);

    DsjSet citl (N);
    DsjSet conl (N);
    F0R(i, N) cin >> cities[i], --cities[i], citl.make_set(i), conl.make_set(cities[i]);

    vector<Edge> edges;
    vector<Edge> interEdges;
    ll allCosts = 0;
    ll useCost = 0;
    F0R(i, M) {
        ll a, b, c;
        cin >> a >> b >> c; --a; --b; allCosts += c;
        if (cities[a] == cities[b]) edges.push_back(Edge {a, b, c});
        else interEdges.push_back(Edge {cities[a], cities[b], c});
    }
    sort(edges.begin(), edges.end());

    
    for (Edge e : edges) {
        if (citl.find_set(e.u) != citl.find_set(e.v)) useCost += e.weight;
        citl.union_sets(e.u, e.v);
    }

    sort(interEdges.begin(), interEdges.end());
    for (Edge e : interEdges) {
        if (conl.find_set(e.u) != conl.find_set(e.v)) useCost += e.weight;
        conl.union_sets(e.u, e.v);
    }
    cout << allCosts - useCost << endl;
}
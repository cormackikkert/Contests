#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

template <typename A>
string to_string(set<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}

vector<ll> H;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    ll N;
    cin >> N;
    vector<ll> P (N);
    for (ll i = 0; i < N; ++i) {
        H.push_back(0);
        cin >> H[i]; 
        P[i] = i;
    }

    sort(P.begin(), P.end(), [](const ll a, const ll b) {
        return H[a] > H[b];
    });

    ll total = 0;
    set<ll> found ({-1, N});
    for (ll ind : P) {
        if (H[ind] == N) {
            found.insert(ind);
            continue;
        }

        ll l0 = *(--found.lower_bound(ind));
        ll l1 = (l0 != -1) ? *(--found.lower_bound(l0)) : -1;
        ll r0 = *found.upper_bound(ind);
        ll r1 = (r0 != N) ? *found.upper_bound(r0) : N;

        ll le = (l0 != -1) ? (l0 - l1) * (r0 - ind) : 0;
        ll ri = (r0 != N ) ? (r1 - r0) * (ind - l0) : 0;

        total += (le + ri) * H[ind];
        found.insert(ind);
    }

    cout << total << endl;
}
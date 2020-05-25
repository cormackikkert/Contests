#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string to_string(vector<ll> x, signed n) {
    string result = "{";
    for (signed i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

ll N, M;
vector<ll> tree;
void update(int k, int x) {
    k += N;
    tree[k] = x;
    bool t = false;
    for (k /= 2; k >= 1; k/=2) {
        if (t) 
            tree[k] = tree[2*k] ^ tree[2 * k + 1];
        else
            tree[k] = tree[2*k] | tree[2 * k + 1];
        t = !t;
    }
}

int main() {
    cin >> N >> M;
    N = pow(2, N);
    tree.resize(2*N);

    for (int i = 0; i < N; ++i) {
        ll val;
        cin >> val;
        update(i, val);
    }

    for (int i = 0; i < M; ++i) {
        ll p, b;
        cin >> p >> b;
        update(p-1, b);
        cout << tree[1] << "\n";
    }
}
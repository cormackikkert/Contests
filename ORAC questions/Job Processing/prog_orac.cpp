#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define F0R(i, n) for (int i = 0; i<n; ++i)

int N, A, B;
vector<vi> M (2);

vi solve(vi et, int j) {
    vi tasks (N);
    vi times (N);
    F0R(i, N) {
        int m  = min_element(et.begin(), et.end()) - et.begin();
        times[i] = et[m];
        et[m] += M[j][m];
    }
    return times;
}

int main() {
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);

    cin >> N >> A; M[0] = vi(A);
    F0R(i, A) cin >> M[0][i];

    cin >> B; M[1] = vi(B);
    F0R(i, B) cin >> M[1][i];

    vi a1 = solve(M[0], 0);
    vi a2 = solve(M[1], 1);
    
    cout << *max_element(a1.begin(), a1.end()) << "\n";
    int b = 0;
    F0R(i, N) b = max(b, a1[i] + a2[N-i-1]);
    cout << b;
}
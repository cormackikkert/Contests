#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = 1LL << 60;
 
using vc = vector<char>;
using vi = vector<int>;
vi arr;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    arr.resize(N);
    vi perm (N);
    F0R(i, N) {
        perm[i] = i;
        cin >> arr[i];
    }

    sort(perm.begin(), perm.end(), [] (const int& lhs, const int& rhs) {
        return arr[lhs] < arr[rhs];
    });

    set<int> proc;
    proc.insert(perm[0]);
    cout << 0 << endl;
    int last = 0;
    FOR(i, 1, N) {
        int ind = perm[i];
        auto above = proc.lower_bound(ind-i);
        auto below = proc.lower_bound(ind-i);

        int best = N;
        int dub = 
        if (above == proc.end()) {
            --below;
            best = *(below);
        } else if (below == proc.begin()) {
            best = *above;
        } else {
            --below;
            best = (abs(*below - ind) > abs(*above - ind)) ? *above : *(below);
        }
        // cout << "ANS: " << arr[ind] << " " << arr[best] << endl;
        cout << "ANS: " << best << endl;
        last += abs(best + i - ind) - 1;
        cout << last << endl;

        proc.insert(ind - i);
    }

}
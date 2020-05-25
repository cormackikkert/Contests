#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
ll INF = LLONG_MAX;
 
using vc = vector<char>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    vi arr (N);
    F0R(i, N) cin >> arr[i];

    multiset<int> seqs;
    R0F(i, N) {
        auto it = seqs.upper_bound(arr[i]);
        if (it != seqs.end()) {
            seqs.erase(it);  
        } 
        seqs.insert(arr[i]);
    }
    cout << seqs.size() << endl;
}
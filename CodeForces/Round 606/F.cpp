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

int N;
unordered_map<int, int> occ;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> N;
    F0R(i, N) {
        int a; cin >> a;
        occ[a]++;
    }

    vector<pair<int, int>> stacks;

    for (auto p : occ) {
        stacks.push_back({p.second, p.first});
    }

    sort(stacks.begin(), stacks.end(), greater<pair<int, int>>());

    int SS = stacks.size();

    vi cumsum (SS+1);
    cumsum[SS] = 0;
    R0F(i, SS) {
        cumsum[i] = stacks[i].first + cumsum[i+1];
    }

    int ba = 0;
    int bh = 0;

    FOR(h, 1, N+1) {
        int lo = 0;
        int hi = stacks.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (stacks[mid].first > h)
                lo = mid + 1;
            else
                hi = mid;
        }
        int w = lo + cumsum[lo] / h;
        if ((w >= h) && (w * h > ba)) {ba = w*h; bh = h;}
    }
    int h = bh;
    int w = ba / bh;
    int cur = 0;
    vector<vi> data (h, vi (w));
    int k = h;
    F0R(i, ba) {
        while (stacks[cur].first == 0 || k == 0) {++cur; k = h;};
        data[i%h][i/h] = stacks[cur].second;
        --stacks[cur].first; --k;
    }
    cout << ba << endl;
    cout << h << " " << w << endl;
    F0R(i, h) {
        F0R(j, w) {
            cout << data[i][(i+j)%w] << " ";
        }
        cout << endl;
    }
}
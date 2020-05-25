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
using pii = pair<int, int>;

bool isBad(vector<pair<int, int>> a, vector<pair<int, int>> b) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    multiset<int> his;
    multiset<int> los; 

    F0R(i, a.size()) {
        while (!q.empty() && q.top().first < a[i].first) {
            int ind = q.top().second;
            los.erase(los.find(b[ind].first));
            his.erase(his.find(b[ind].second));
            q.pop();
        } 

        // cout << "REE: " << his.size() << " " << los.size() << endl;
        // all B los < a hi
        // all B his > a lo
        if (his.size() > 0 && (*(his.begin()) < b[i].first || *(los.rbegin()) > b[i].second)) {
            // cout << *(his.begin()) << " " << b[i].first << " " << b[i].second << " " << *(los.rbegin())  << endl;
            return true;
        }
 
        los.insert(b[i].first);
        his.insert(b[i].second);

        q.push({a[i].second, i});
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    vector<pair<int, int>> arr1;
    vector<pair<int, int>> arr2;
    F0R(i, N) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        arr1.push_back({a, b});
        arr2.push_back({c, d});
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    if (isBad(arr1, arr2) || isBad(arr2, arr1)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
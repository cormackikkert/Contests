#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("dollin.txt", "r", stdin);
    freopen("dollout.txt", "w", stdout);
    int N;
    cin >> N;
    vector<int> dolls (N);
    for (int i = 0; i < N; ++i) cin >> dolls[i];
    multiset<int> production;
    for (auto it = dolls.rbegin(); it != dolls.rend(); ++it) {
        
        int item = *it;
        
        if (production.size() == 0 || *production.begin() >= item) {
            production.insert(item);
            continue;
        }
        multiset<int>::iterator pos = production.lower_bound(item);
        
        --pos;

        production.erase(pos);
        production.insert(item);
        
    }

    cout << production.size() << endl;
}
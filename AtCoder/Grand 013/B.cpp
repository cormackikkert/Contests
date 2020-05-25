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
using vb = vector<bool>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M; cin >> N >> M;
    vector<vi> graph (N);
    F0R(i, M) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vb inPath (N);
    deque<int> path; 
    path.push_front(0);
    path.push_back(graph[0][0]);
    inPath[0] = true;
    inPath[graph[0][0]] = true;

    while (true) {
        bool leftValid = true;
        for (int n : graph[path.front()]) if (!inPath[n]) {
            leftValid = false; 
            path.push_front(n);
            inPath[n] = true;
            break;
        }

        bool rightValid = true;
        for (int n : graph[path.back()]) if (!inPath[n]) {
            rightValid = false;
            path.push_back(n);
            inPath[n] = true;
            break; 
        }

        if (leftValid && rightValid) break;
    }

    cout << path.size() << endl;
    for (int item : path) {
        cout << item + 1<< " ";
    }
    cout << endl;

}
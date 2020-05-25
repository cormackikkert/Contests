#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef pair<int,int> pii;

const int N = 300005;
int n, m, f[N], g[N];
bool taken[N];
priority_queue<int> q[1<<6];

int main() {
    cin >> n >> m;
    
    REP(j,6) {
        string s;
        cin >> s;
        REP(i,n)
            if(s[i] == '1')
                f[i] |= (1 << j);
    }
    
    REP(i,n)
      REP(j, 1<<6) if ((j & ~f[i]) == 0)
        q[j].push(i);
    
    REP(j,6) {
        string s;
        cin >> s;
        REP(i,m)
            if(s[i] == '1')
                g[i] |= (1 << j);
    }
    
    CL(taken);
    REP(i,m) {
        int r = g[i];
        while (q[r].size() && taken[q[r].top()]) q[r].pop();
       if (!q[r].size()) {
          cout << -1;
       } else {
          int id = q[r].top(); q[r].pop();
          cout << (id+1);
        taken[id] = true;
      }
      if (i < m-1) cout << " ";
    }
    cout << endl;
}

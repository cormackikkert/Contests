#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int , int> pii;
 
const int N = 2e5+10 , mod = 1e9+7;
 
int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while(t--){
      int n , m;
      cin >> n >> m;
      vector <int> g[n];
      for(int i = 0 ; i < m ; i++){
         int u , v;
         cin >> u >> v;
         u--; v--;
         g[u].push_back(v);
      }
      int dp[n];
      memset(dp , 0 , sizeof(dp));
      vector <int> ans;
      for(int i = 0 ; i < n ; i++){
         if(dp[i] >= 2)
            ans.push_back(i);
         else{
            for(int u : g[i])
               dp[u] = max(dp[u] , dp[i] + 1);
         }
      }
      cout << ans.size() << "\n";
      for(int x : ans)
         cout << x + 1 << " ";
      cout << "\n";
   }
   return 0;
}
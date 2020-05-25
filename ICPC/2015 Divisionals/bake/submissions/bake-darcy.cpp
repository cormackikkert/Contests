#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin >> n >> m;
  
  vector<int> p(n), q(m);

  for(int j=0;j<6;j++){
    string s; cin >> s;
    for(int i=0;i<n;i++)
      if(s[i] == '1')
	p[i] |= (1 << j);
  }

  for(int j=0;j<6;j++){
    string s; cin >> s;
    for(int i=0;i<m;i++)
      if(s[i] == '1')
	q[i] |= (1 << j);
  }

  vector<vector<int> > v(1 << 6);
  for(int i=0;i<n;i++)
    v[p[i]].push_back(i+1);
    
  vector<int> ans;
  
  for(int i=0;i<m;i++){
    int best_j = -1;
    for(int j=0;j<(1 << 6);j++)
      if((q[i] & j) == q[i] && v[j].size())
	if(best_j == -1 || v[best_j].back() < v[j].back())
	  best_j = j;
    
    if(best_j == -1)
      ans.push_back(best_j);
    else{
      ans.push_back(v[best_j].back());
      v[best_j].pop_back();
    }
  }
  
  for(int i=0;i<m;i++)
    cout << (i ? " " : "") << ans[i];
  cout << endl;
}

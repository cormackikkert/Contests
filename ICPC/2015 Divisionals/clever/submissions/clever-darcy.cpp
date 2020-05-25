#include <bits/stdc++.h>
using namespace std;

int count(const vector<string>& names,const string& word){
  if(word.length() != names.size()) return false;
  int n = word.length();
  
  vector<int> DP(1 << n);
  DP[0] = 1;
  
  for(int i=1;i<(1 << n);i++){
    char lett = word[__builtin_popcount(i)-1];
    for(int j=0;j<n;j++)
      if(((i >> j) & 1) && names[j].find(lett) != string::npos)
        DP[i] += DP[i ^ (1 << j)];
  }

  return DP[(1 << n)-1];
}

int main(){
  int n,k;
  cin >> n >> k;
  
  vector<string> names(n);
  for(int i=0;i<n;i++)
    cin >> names[i];

  for(int i=0;i<k;i++){
    string word;
    cin >> word;
    cout << count(names,word) << endl;
  }
}

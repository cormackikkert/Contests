#include <bits/stdc++.h>
using namespace std;

const int coins[] = {1,2,5,10,20,50};

vector<int> read(){
  vector<int> v(6);
  for(int i=0;i<6;i++) cin >> v[i];
  return v;
}

bool make_change(vector<int>& machine,int amt){
  for(int i=5, tmp_amt = amt;i>=0;i--){
    int ctr = 0;
    while(tmp_amt >= coins[i]){
      tmp_amt -= coins[i];
      ctr++;
    }
    if(ctr > machine[i])
      return false;
  }
  
  for(int i=5;i>=0;i--)
    while(amt >= coins[i]){
      amt -= coins[i];
      machine[i]--;
    }
  return true;      
}

int main(){
  vector<int> std =read();
  
  vector<int> machine = std;
  int T; cin >> T;
  int ans = 0;
  while(T--){
    int V; cin >> V;
    vector<int> d = read();
    int amt = inner_product(coins,coins+6,d.begin(),0);
    for(int i=0;i<6;i++) machine[i] += d[i];
    amt -= V;
    if(make_change(machine,amt)) continue;
    int before = amt;
    for(amt++ ; !make_change(machine,amt) ; amt++) ;
    machine = std;
    ans += amt-before;
  }
  cout << ans << endl;
}

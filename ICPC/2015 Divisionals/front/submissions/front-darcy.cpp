#include <bits/stdc++.h>
using namespace std;

vector<vector<double> > DP;
int P[3];

int n,h;

int fix(int y){
  if(y < 0) return 0;
  if(y > h) return h;
  return y;
}

double f(int i,int j){
  if(DP[j][i] >= -0.5) return DP[j][i];
  if(i == n) return 0;
  
  double ans = 0;
  for(int x=-1;x<=1;x++){
    int nJ = fix(j+x);
    ans += P[x+1] / 100.0 * (f(i+1,nJ) + min(j,nJ) + (j == nJ ? 0 : 0.5));
  }
  
  return DP[j][i] = ans;
}

int main(){
  int a;
  cin >> n >> h >> a;
  
  for(int i=0;i<3;i++) cin >> P[i];
    
  DP.assign(h+1,vector<double>(n+1,-1));

  cout << fixed << setprecision(10) << f(0,a) << endl;
}

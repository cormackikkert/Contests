#include <bits/stdc++.h>
using namespace std;

double EPS = 1e-8;

struct Umb {
  int x,y,r;
};

double dist(const Umb& a,const Umb& b){
  return max(0.0,hypot(a.x-b.x,a.y-b.y)-a.r-b.r);
}

int main(){
  int n,K,x,y;
  cin >> n >> K >> x >> y;
  
  vector<Umb> p(n);
  for(int i=0;i<n;i++)
    cin >> p[i].x >> p[i].y >> p[i].r;
  p.push_back({0,0,0}); // Starting loction
  n++;
  
  vector<vector<double> > A(n,vector<double>(n,-1));
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(dist(p[i],p[j]) > K+EPS) continue;
      A[i][j] = dist(p[i],p[j]);
    }
  
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
	if(A[i][k] < -0.5 || A[k][j] < -0.5) continue;
	if(A[i][j] < -0.5 || A[i][j] > A[i][k] + A[k][j])
	  A[i][j] = A[i][k] + A[k][j];
      }
  
  Umb ball = {x,y,0};

  double best = -1;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(A[n-1][i] < -0.5) continue;
      if(A[j][n-1] < -0.5) continue;
      double d = dist(p[i],ball) + dist(ball,p[j]);
      if(d > K+EPS) continue;
      
      d += A[n-1][i] + A[j][n-1];
      
      if(best < -0.5 || best > d)
	best = d;
    }

  cout << fixed << setprecision(10);
  if(best < -0.5) cout << "-1" << endl;
  else cout << best << endl;
      
}

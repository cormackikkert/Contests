#include <bits/stdc++.h>
using namespace std;

struct Umb {
  long long x,y,r;
};

// Distance from edge-to-edge of umbrellas
double dist(const Umb& a,const Umb& b){
  return max(0.0,hypot(a.x-b.x,a.y-b.y)-a.r-b.r);
}

// Distance squared from centre of umbrellas
long long dist2c(const Umb& a,const Umb& b){
  return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

// Return true if sqrt(a) + sqrt(b) <= c
bool leq(long long a,long long b,long long c){
  if(c < 0) return false;
  long long m = c*c - a - b;
  return (m >= 0 && 4*a*b <= m*m);  
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
    for(int j=0;j<n;j++)
      if(leq(dist2c(p[i],p[j]), 0, K+p[i].r+p[j].r))
	A[i][j] = dist(p[i],p[j]);
  
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

      long long d2_i = dist2c(p[i],ball), d2_j = dist2c(ball,p[j]);

      if(!leq(d2_i,d2_j,K+p[i].r+p[j].r)) continue;
      
      double d = A[n-1][i] + dist(p[i],ball) + dist(ball,p[j]) + A[j][n-1];
      
      if(best < -0.5 || best > d)
	best = d;
    }

  cout << fixed << setprecision(10);
  if(best < -0.5) cout << "-1" << endl;
  else cout << best << endl;
      
}

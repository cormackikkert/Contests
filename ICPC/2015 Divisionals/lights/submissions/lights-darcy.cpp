#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, d; cin >> n >> d;

  bool ans = true;
  for(int i=0;i<n;i++){
    int x,a,g,r; cin >> x >> a >> g >> r;
    if(x < a || ((x-a) % (g+r) > g))
      ans = false;
  }
  cout << (ans ? "YES" : "NO") << endl;
}

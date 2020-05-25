#include <bits/stdc++.h>
using namespace std;
vector<int>x={0,0};
vector<vector<int>>g;
vector<bool>v;
int s(int a, int c) {
 x[c]++;v[a]=1;
 for (int n:g[a])(v[n])?0:s(n,1-c);
}
int main() {freopen("arthin.txt","r",stdin);freopen("arthout.txt","w",stdout);int N,P;cin>>N>>P;
 g.resize(N); v.resize(N);
 for(int i=0;i<P;++i){int a,b;cin>>a>>b;--a;--b;g[a].push_back(b);g[b].push_back(a);}
 int t=0;
 for (int i = 0; i < N; ++i)if(!v[i])x={0,0},s(i, 0),t+=max(x[0],x[1]);
 cout << t << endl;
}
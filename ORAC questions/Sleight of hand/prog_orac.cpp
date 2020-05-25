#include <bits/stdc++.h>
using namespace std;
int main() {
 freopen("handin.txt", "r", stdin);
 freopen("handout.txt", "w", stdout);
 int N,S,K,a,b;cin>>N>>S>>K;
 for(int i=0;i<K;++i){cin>>a>>b;if(a==S)S=b;else if(a<S&&b>=S)--S;else if(a>S&&b<=S)++S;}
 cout << S << endl;
}
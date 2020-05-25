#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=100005;
const int B=sqrt(max_n);
int n,k;
bool p[max_n];
int pri[max_n];
int cnt;
int a[max_n];
map<vector<int>,int> mp[max_n];
void sieve(int n){
    p[0]=p[1]=true;
    for(int i=2;i<=n;i++){
        if(!p[i])pri[++cnt]=i;
        for(int j=1;j<=cnt&&1ll*i*pri[j]<=n;j++){
            p[i*pri[j]]=true;
            if(i%pri[j]==0)break;
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    sieve(B);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    ll ans=0;
    for(int i=1;i<=n;i++){
        //for(int j=1;j<=)
        vector<int> v;
        vector<int> t; 
        for(int j=1;j<=cnt;j++){
            int c=0;
            while(a[i]%pri[j]==0)a[i]/=pri[j],c++;
            v.push_back(c%k);
            t.push_back((k-c%k)%k);
        }
        if(k==2||a[i]==1)ans+=mp[a[i]][t];
        mp[a[i]][v]++;
    }
    printf("%lld\n",ans);
    return 0;
}
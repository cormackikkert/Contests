#include <bits/stdc++.h>
 
#define pb push_back
#define left(x) ((x)*(2))
#define right(x) (((x)*(2))+1)
#define F first
#define S second
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef pair <int , int> pii;
typedef pair <pii , int> ppii;
typedef pair <int , pii> pipi;
typedef pair <ll , ll> pll;
 
const int maxn = 2e5+10 , inf = 1e9+10 , MOD = 1e9+7 , Sq = 449 , msk=(1<<20) , pr = 522017 , PR=71;
const ll INF = 1e18+10;
 
vector < pair <pii , int> > v[Sq];
int a[maxn] , t[1000010];
ll res[maxn] , ans=0;
 
inline void add(int x){
    t[x]++;
    ans+=-x+2*x*t[x];
}
 
inline void del(int x){
    ans-=(-x+2*x*t[x]);
    t[x]--;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,q;
    scanf("%d%d" , &n , &q);
    for(int i=0 ; i<n ; i++)
        scanf("%d" , &a[i]);
    for(int i=0,l,r ; i<q ; i++){
        scanf("%d%d" , &l , &r);
        l-- , r--;
        v[l/Sq].pb({{r , l} , i});
    }
    for(int i=0 ; i<Sq ; i++)
        sort(v[i].begin() , v[i].end());
    int l=0 , r=0;
    t[a[0]]=1;
    ans=a[0];
    for(int i=0 ; i<Sq ; i++){
        for(pair <pii , int> u:v[i]){
            while(r<u.F.F)
                add(a[++r]);
            while(r>u.F.F)
                del(a[r--]);
            while(l>u.F.S)
                add(a[--l]);
            while(l<u.F.S)
                del(a[l++]);
            res[u.S]=ans;
        }
    }
    for(int i=0 ; i<q ; i++)
        printf("%lld\n" , res[i]);
    return 0;
}
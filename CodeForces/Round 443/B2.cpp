#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int max_n = 1e5+10;
 
vector<int> b;
int n,m,k;
int a[max_n];
 
int f(int i,int j,int m,int k){
    if(i>j) return 0;
    assert(i>=0 && i<=(int)b.size()-1);
    assert(j>=0 && j<=(int)b.size()-1);
 
    if(b[i]!=b[j]){
        return m*(j-i+1);
    }
 
    int l = j;
    while(l>=i && b[j]==b[l]) {
        assert(l>=0 && l<=(int)b.size()-1);
        l--;
    }
    l++;
 
    //all characters are equal
    if(l==i){
        return ((j-i+1)*m)%k;
    }
 
    int r = i;
    while(r<=j && (j-l+1+(r-i+1))<k && b[i]==b[r]) {
        assert(r>=0 && r<=(int)b.size()-1);
        r++;
    }
    assert(r>=0 && r<=(int)b.size()-1);
    if(b[r]!=b[j]) r--;
 
    if((r-i+1)+(j-l+1)<k){
        return m*(j-i+1);
    }else{
        
        int ans = f(r+1,l-1,m,k);
        if(ans==0) return 0;
        else return ans+k;
    }
}
 
signed main(){
    cin>>n>>k>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
 
    int count = 0;
    for(int i=0;i<n;i++){
        if(b.size()==0){
            b.push_back(a[i]);
            count=1;
            continue;
        }
        if(b.back()==a[i]){
            b.push_back(a[i]);
            count++;
        }else{
            b.push_back(a[i]);
            count=1;
        }
        if(count==k){
            for(int w=0;w<k;w++) b.pop_back();
            if(b.size()>0){
                count = 0;
                int j = ((int)b.size())-1;
                while(j>=0 && b[j]==b.back()){
                    count++;
                    j--;
                }
            }
        }
    }
    cout<<f(0,(int)b.size()-1,m,k)<<endl;
 
 
}
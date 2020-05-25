#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define pii pair<int, int>
#define forr(i,a,n) for (int i = (a); i < (n); ++i)
#define rforr(i,a,n) for (int i = (a); i > (n); --i)
#define ALL(x) x.begin(),x.end()
#define LEN(X) ((int)(X).size())
#define CASET int _T; cin >> _T; forr(caset,0,_T)
#define int ll
 
int mins(vi red, vi blue, vi green, int r, int b, int g) {
    // for each value of r, first find closest b, then closest g to average
    int j=0,k=0; // j blue, k green
    int minsum = LLONG_MAX;
    forr(i,0,r) {
            while (blue[j]<red[i] && j+1<b) j++;
            int x = (red[i]+blue[j])/2;
            while (green[k]<x && k+1<g) k++;
 
            minsum = min(minsum, (red[i]-blue[j])*(red[i]-blue[j]) 
                + (red[i]-green[k])*(red[i]-green[k])  + (blue[j]-green[k])*(blue[j]-green[k]));
            if (j!=0) {
                j--;
                minsum = min(minsum, (red[i]-blue[j])*(red[i]-blue[j]) 
                 + (red[i]-green[k])*(red[i]-green[k])  + (blue[j]-green[k])*(blue[j]-green[k]));
                if (k!=0) {
                    k--;
                    minsum = min(minsum, (red[i]-blue[j])*(red[i]-blue[j]) 
                     + (red[i]-green[k])*(red[i]-green[k])  + (blue[j]-green[k])*(blue[j]-green[k]));
                    j++;
                    minsum = min(minsum, (red[i]-blue[j])*(red[i]-blue[j]) 
                     + (red[i]-green[k])*(red[i]-green[k])  + (blue[j]-green[k])*(blue[j]-green[k]));
                    j--;
                }
            } else if (k!=0) {
                    k--;
                    minsum = min(minsum, (red[i]-blue[j])*(red[i]-blue[j]) 
                     + (red[i]-green[k])*(red[i]-green[k])  + (blue[j]-green[k])*(blue[j]-green[k]));
            }
    }
    return minsum;
}
 
main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("input.txt","r",stdin);
    
    CASET {
        int r,g,b;
        cin >>r >> g >> b;
        vi red(r), blue(b), green(g);
        forr(i,0,r) cin >> red[i];
        forr(i,0,g) cin >> green[i];
        forr(i,0,b) cin >> blue[i];
        sort(ALL(red));
        sort(ALL(green));
        sort(ALL(blue));
 
        int res = mins(red,blue,green,r,b,g);
        res = min(res, mins(red,green,blue,r,g,b));
        res = min(res, mins(blue,red,green,b,r,g));
        res = min(res, mins(blue,green,red,b,g,r));
        res = min(res, mins(green,red,blue,g,r,b));
        res = min(res, mins(green,blue,red,g,b,r));
        
        cout << res << '\n';
 
    }
 
 
}
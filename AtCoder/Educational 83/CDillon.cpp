#include <bits/stdc++.h>
using namespace std;
#define EB emplace_back
#define G(i,x) get<i>(x)
#define F(i,s,n) for(int i = s; i < n; i++)
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;

ll arr[105];

int main() {
	iostream::sync_with_stdio(false);
	int a, b;
	int T;
	cin>>T;
	F(o,0,T){
		int n, k;
		cin>>n>>k;
		F(i,0,n){
			cin>>arr[i];
		}
		long long currPo = 1;
		int didfailt = 0;
		while (currPo < int(2e16)) {
			int fails = 0;
			F(i,0,n){
				if (arr[i] % k == 1) {
					if (fails == 0){
						fails = 1;
						arr[i] /= k;
					}else{
						fails = 2;
						break;
					}
				} else if (arr[i] % k == 0) {
					arr[i] /= k;
				} else {
					fails = 2;
					break;
				}
			}
			if (fails > 1) {
				didfailt = 1;
				break;
			}
			currPo *= k;
		}
		if(didfailt) {
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
}
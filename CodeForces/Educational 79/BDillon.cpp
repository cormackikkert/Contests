#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vec vector<ll>
#define sortv(a); sort(a.begin(), a.end());
#define rev(a); reverse(a.begin(), a.end());
 
ll MOD = 1000000007;
ll INF = 1LL << 60;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) {
		ll n, s;
		cin >> n >> s;
		vec a (n);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		ll skip = 0;
		ll biggest = -1;
		ll biggestInd = -1;
		ll temp = 0;
		if (sum == s) {
			skip = 0;
		} else {
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > biggest) {
				biggest = a[i];
				biggestInd = i;
			}
			temp += a[i];
			if (temp > s) {
				if (a[i + 1] < biggest) {
					skip = biggestInd + 1;
				}
 
				break;
			}
		}
		}
		
		cout << skip << "\n"; // indexing starts at 1
	}
}
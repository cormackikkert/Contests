#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define int long long
using vi = vector<int>;

vi actual = {0b1110111, 0b0010010,0b1011101,0b1011011,0b0111010,0b1101011,0b1101111,0b1010010,0b1111111,0b1111011};
int dp [2005][2005];
vi nums;
vi actual_ans;

int N, K;
int recurse(int pos, int rem) {
	if (pos == N) {
		if (rem == 0) {
			return 0;
		} else {
			return -2;
		}
	}

	if (dp[pos][rem] != -1) return dp[pos][rem];

	R0F(i, 10) {
		// print(i, nums[pos], actual[i]);
		if ((nums[pos] & actual[i]) == nums[pos]) {
			int changes = __builtin_popcount(nums[pos] ^ actual[i]);
			// print(i, changes);
			if (rem >= changes) {
				int other = recurse(pos + 1, rem - changes);
				if (other != -2) {
					actual_ans[pos] = i;
					dp[pos][rem] = i;
					return i;
				}
			}
		}
	}
	dp[pos][rem] = -2;
	return -2;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	actual_ans.resize(N);
	F0R(i, 2005) F0R(j, 2005) dp[i][j] = -1;
	F0R(i, N) {
		string x; cin >> x;
		int num = 0;
		F0R(j, 7) {
			num += (x[j] == '1') << (7-j-1);
		}
		nums.push_back(num);
	}

	int res = recurse(0, K);
	if (res == -2) 
		cout << -1 << endl;
	else {
		for (int x : actual_ans) cout << x;
		cout << endl;
	}
}
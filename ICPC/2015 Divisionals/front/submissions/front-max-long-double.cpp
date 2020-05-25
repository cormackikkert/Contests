#include <bits/stdc++.h>

using namespace std;

int N, H, A;
long double pm, p, pa;

int main() {
	cin >> N >> H >> A >> pm >> p >> pa;
	pm /= 100;
	p /= 100;
	pa /= 100;
	vector<long double> dp(H+1), next;

	for (int i = N-1; i >= 0; --i) {
		next = dp;
		for (int h = 0; h <= H; ++h) {
			long double a = h + dp[h];
			long double b = h + dp[min(H, h+1)];
			if (h < H)
				b += 0.5;
			long double c = h + dp[max(0, h-1)];
			if (h > 0)
				c -= 0.5;
			next[h] = a*p + b*pa + c*pm;
		}
		dp = next;
	}

	cout << fixed << setprecision(20) << dp[A] << endl;

}

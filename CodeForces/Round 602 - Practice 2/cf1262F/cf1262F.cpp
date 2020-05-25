#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)

long long MOD = 998244353;

long long powm(long long base, long long exp) {
	if (exp <= 0) return 1;
	if (base <= 0) return 0;
	long long val = powm(base, exp / 2);
	val = (val * val) % MOD;
	if (exp % 2 == 1) {
		val *= base;
		val %= MOD;
	}
	return val;
}


long long modInverse(long long a) {
	return powm(a, MOD - 2);
}

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
		long long n, k;
		in >> n >> k;
		vector<int> ans(n);
		
		
		for (int i = 0; i < n; ++i) {
			in >> ans[i];
		}

		// count ways to get 0
		int allZeros = 1;
		int total = 0;
		for (long long i = 0; i < n; ++i) {
			if (ans[i] != ans[(i + 1) % n]) {
				allZeros *= k - 2;
				++total;
			}
			else
				allZeros *= k;
			allZeros %= MOD;
		}

		long long getZero = 1;

		
		for (int i = 0; i < total / 2; ++i) {
			getZero *= (total - i);
			getZero %= MOD;
		}
		for (int i = 0; i < n - total; ++i) {
			getZero *= k;
			getZero %= MOD;
		}

		if (total % 2) getZero *= (k - 2) * (total - total/2);
		
		getZero %= MOD;

		out << ((powm(k, n) - getZero - allZeros) * modInverse(2)) % MOD << endl;
		
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}

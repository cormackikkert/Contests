#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp [61][61][3]; 
ll MOD = pow(10, 9) + 7;
ll L, R;

ll fac[2*(int)10e5 + 1];

ll powm(ll base, ll exp) {
	if (exp <= 0) return 1;
	if (base <= 0) return 0;
	ll val = powm(base, exp / 2);
	val = (val * val) % MOD;
	if (exp % 2 == 1) {
		val *= base;
		val %= MOD;
	}
	return val;
}

ll modInverse(ll a) {
	return powm(a, MOD - 2);
}

ll choose(ll n, ll k) {
	return ((fac[n] * modInverse(fac[k]) % MOD) * modInverse(fac[n - k])) % MOD;
}


ll above(ll num, ll digits, ll length, ll k) {
    --length;
    if (num == 0) k = 0;

    // cout << num << " " << digits << " "  << length << endl;
    if (dp[length][digits][k] != -1) return dp[length][digits][k];

    if (length == 0) {
        if (digits > 1)  return 0;
        if (num == 1) return (digits == 1);
        if (num == 0) return 1;
    }

    if (digits > length + 1) return 0;

    ll result;
    if (num & (1 << length)) {
        if (digits > 0) 
            result = above(num & ~(1 << length), digits - 1, length, k);
        else 
            result = 0;
    } else {
        result = above(num, digits, length, k) + ((digits > 0) ? above(0, digits - 1, length, 0) : 0);
    }
    result %= MOD;

    dp[length][digits][k] = result;
    
    return result;
}

ll above(ll num, ll digits, ll length) {
    return above(num, digits, length, 1 + (num > L));
}

int above_brute_force(int num, int digits, int length) {
    int total = 0;
    for (int i = num; i < pow(2, length); ++i) {
        if (__builtin_popcount (i) == digits) ++total;
    }
    return total;
}

ll occ[61][61][2][2]; 
ll occurance(ll ones, ll length, ll considerBig, ll considerSmall) {
    if (ones < 0) return 0; 

    if (length == 1) {
        bool r = considerBig && (R &  (1 << length));
        bool l = considerSmall && (L & (1 << length));
        if (r && l) return (ones == 1);
        if (r) return (ones == 1);
        if (l) return (ones == 1);
        else return (ones <= 1);
    }

    --length;

    

    if (occ[ones][length][considerBig][considerSmall] != -1)
        return occ[ones][length][considerBig][considerSmall];

    
    bool r = considerBig && (R & (1 << length));
    bool l = considerSmall && (L & (1 << length));

    cout << "occurance("<<ones<<", "<<length+1<<", " << considerBig<<", " << considerSmall<<")"<<endl;
    cout << L << " " << (L & ~(1 << length)) << " " << length << " " <<r<<l<< endl;
    ll result; 
    if (r && l) {
        cout <<"1"<<endl;
        result =  occurance(ones - 1, length, considerBig, considerSmall); 
    } else if (r) {
        cout <<"2"<<endl;
        result = occurance(ones - 1, length, considerBig, false) +
                occurance(ones, length, false, considerSmall);
    } else if (l) {
        cout <<"3"<<endl;
        result = occurance(ones - 1, length, considerBig, considerSmall);
    } else {
        cout <<"4"<<endl;
        result = occurance(ones - 1, length, considerBig, false) +
                occurance(ones, length, false, considerSmall);
    }
    occ[ones][length][considerBig][considerSmall] = result;
    return result;
}
 
ll below(ll num, ll digits, ll length) {
    if (digits == 0) {
        return (length == 1);
    }
    if (digits > length) return 0;
    return choose(length - 1, digits - 1) - above(num, digits, length) + (__builtin_popcount(num) == digits);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	fac[0] = 1;
	for (int i = 1; i <= 100; ++i) fac[i] = (i * fac[i - 1]) % MOD;

    for (int i = 0; i <= 60; ++i)
        for (int j = 0; j <= 60; ++j)
            for (int k = 0; k < 3; ++k)
                dp[i][j][k] = -1;

    for (int i = 0; i <= 60; ++i)
        for (int j = 0; j <= 60; ++j)
            for (int k = 0; k < 2; ++k)
                for (int l = 0; l < 2; ++l)
                    occ[i][j][k][l] = -1;

    L = 8;
    R = 13;
    cout << occurance(2, 4, true, true) << endl;
    /*
    cin >> L >> R;

    ll loDigits = log2(L) + 1;

    ll cumAbove [61];
    cumAbove[60] = above(L, 60, loDigits);
    for (int i = 59; i >= 0; --i) cumAbove[i] = cumAbove[i+1] + above(L, i, loDigits);
    
    ll hiDigits = log2(R) + 1;
    ll cumBelow [61];
    cumBelow[60] = below(R, 60, hiDigits); 
    for (int i = 59; i >= 0; --i) cumBelow[i] = cumBelow[i+1] + below(R, i, hiDigits);
    
    ll total = 0;

    if (loDigits == hiDigits) {
        cout << "REE" << endl;
    } else {
        for (ll ones  = 0; ones <= loDigits; ++ones) {
            total += above(L, ones, loDigits) * pow(2, loDigits - ones);
            total %= MOD;
        }
        cout << total << endl;
        L = 1 << (hiDigits);
        for (ll length = loDigits + 1; length < hiDigits; ++length) {
            for (ll ones = 0; ones < length; ++ones) {
                total += choose(length - 1, ones) * pow(2, length - ones - 1);
                total %= MOD;
            }
        }
        
        cout << total << endl;

        
        for (ll ones  = 0; ones <= hiDigits; ++ones) {
            // cout << ones << " " << below(R, ones, hiDigits) << " " << cumBelow[ones] << endl;
            total += occurance(ones, hiDigits, true, true);
            total %= MOD;
        }
        
    }

    
    cout << total << endl;
    /*
    cout << above(L, 3, loDigits) << endl;
    cout << above_brute_force(L, 3, loDigits) << endl;
    cout << cumAbove[2] << " " << cumAbove[3] << " " << cumAbove[4] << endl;
    */
}
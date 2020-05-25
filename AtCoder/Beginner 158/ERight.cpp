#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fst first
#define snd second

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

ll mod = 998244353;
ll modpow(ll b, ll e) {
  ll ans = 1;
  for (; e; e >>= 1, b *= b, b %= mod, ans %= mod) if (e&1) ans *= b;
  return ans;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int n, p;
  string s;
  cin >> n >> p >> s;

  if (p==2 or p==5) {
    vvi dp(n, vi(p));
    dp[0][(s[0]-'0')%p] = 1;
    rep(i,1,n) {
      rep(j,0,p) {
        dp[i][(j*10+(s[i]-'0'))%p] += dp[i-1][j];
      }
      ++dp[i][(s[i]-'0')%p];
    }
  
    ll ans = 0;
    rep(i,0,n) ans += dp[i][0];
    return cout << ans << endl, 0;
  }
  mod = p;

  vi cnt(p);
  cnt[0] = 1;
  int t = 0;
  ll ans = 0;
  for (int i = n-1; i >= 0; --i) {
    t += modpow(10, n-1-i) * (s[i]-'0'); t %= p;
    ans += cnt[t];
    ++cnt[t];
  }
  cout << ans << endl;
}

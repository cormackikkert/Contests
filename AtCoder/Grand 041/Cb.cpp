//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll

using namespace std;
using namespace __gnu_pbds;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
int MOD=1000000007;
int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w,bool fl=false)
{
	cout<<w.size()<<en;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<en;
	if (fl) cout<<flush;
}

void M998()
{
	swap(MOD,MOD2);
}

ll raand()
{
	ll a=rund();
	a*=RAND_MAX;
	a+=rund();
    return a;
}

#define rand raand

ll raaand()
{
	return raand()*(MOD-7)+raand();
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}

template<class T>
void eras(vector<T>& a,T b)
{
	a.erase(find(a.begin(),a.end(),b));
}

string its(ll k,int base=10)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%base)+'0');
		k/=base;
	}
	reverse(a.begin(),a.end());
	return a;
}

ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}

ll min(int a,ll b)
{
	if (a<b) return a;
	return b;
}

ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}

ll max(int a,ll b)
{
	if (a>b) return a;
	return b;
}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

inline int mult(ll a,ll b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

int divide(int a,int b)
{
	return mult(a,pot(b,MOD-2));
}

inline int sub(int a,int b)
{
	if (a-b>=0) return a-b;
	return a-b+MOD;
}

inline int add(int a,int b)
{
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

const int N=310;
int n,r[N],c[N],m;
vector<pair<pii,pii>> v;
string h[N];
int ta[N][N];

bool hor(int i,int j,bool rem=0)
{
	if (rem)
	{
		--c[j];
		--c[j+1];
		--r[i];
		--ta[i][j];
		--ta[i][j+1];
		v.pop_back();
		return 0;
	}
	else
	{
		++r[i];
		++c[j];
		++c[j+1];
		++ta[i][j];
		++ta[i][j+1];
		v.pb({{i,j},{i,j+1}});
		return r[i]<=3*m && c[j]<=3*m && c[j+1]<=3*m && ta[i][j]==1 && ta[i][j+1]==1;
	}
}

bool ver(int i,int j,bool rem=0)
{
	if (rem)
	{
		--r[i];
		--r[i+1];
		--c[j];
		--ta[i][j];
		--ta[i+1][j];
		v.pop_back();
		return 0;
	}
	else
	{
		++c[j];
		++r[i];
		++r[i+1];
		++ta[i][j];
		++ta[i+1][j];
		v.pb({{i,j},{i+1,j}});
		return r[i]<=3*m && c[j]<=3*m && r[i+1]<=3*m && ta[i][j]==1 && ta[i+1][j]==1;
	}
}

void doV(int c,int p)
{
	if (c==0)
	{
		for (int i=0;i<n;++i) h[i]=string(n,'.');
		char ch='a';
		for (auto a: v)
		{
			h[a.x.x][a.x.y]=ch;
			h[a.y.x][a.y.y]=ch;
			++ch;
			if (ch>'z') ch='A';
		}
		for (int i=0;i<n;++i) cout<<h[i]<<en;
		exit(0);
	}
	for (int k=p;k<n*(n-1);++k)
	{
		int i=k/n,j=k%n;
		if (ver(i,j)) doV(c-1,k);
		ver(i,j,1);
	}
}

void doC(int c,int p)
{
	if (c==0) doV(n*m,0);
	else
	{
		for (int k=p;k<n*(n-1);++k)
		{
			int j=k/n,i=k%n;
			if (hor(i,j)) doC(c-1,k);
			hor(i,j,1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>m;
	doC(n*m,0);
}





#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void print() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void print(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); print(ts...); 
	}
}

using namespace output;

bool canDo(int N, int M, int A, int B) {
	if (N&1) A = max(0, A - M / 2);
	if (M&1) B = max(0, B - N / 2);
	return (A+1)/2 *4 + (B+1)/2 * 4 <= (N/2*2) * (M/2*2);
}

void fill(vector<vector<char>>& arr, int sy, int sx, int N, int M, int A, int B) {
	

	
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, A, B; cin >> N >> M >> A >> B;

	vector<vector<char>> arr (N, vector<char> (M, '.'));
	
	if ((N&1) && (M&1) && (2*(A+B) == N*M-1) && ((A-M/2)&1) && ((B-N/2)&1)) {
		for (int i = 1; i+1 < M && A; i += 2) if (A) {arr[N-1][i] = '<'; arr[N-1][i+1] = '>'; --A;}
		for (int i = 1; i+1 < N && B; i += 2) if (B) {arr[i][0] = '^'; arr[i+1][0] = 'v'; --B;}
		if (A) {arr[0][0] = '<'; arr[0][1] = '>'; --A;}
		if (B) {arr[0][2] = '^'; arr[1][2] = 'v'; --B;}
		for (int i = 0; i+1 < N; i += 2) for (int j = 1; j+1 < M; j += 2) if (i != 0 || j != 1) {
			if (A) {
				arr[i][j] = '<'; arr[i][j+1] = '>';
				arr[i+1][j] = '<'; arr[i+1][j+1] = '>';
				A -= 2;
			} else if (B) {
				arr[i][j] = '^'; arr[i+1][j] = 'v';
				arr[i][j+1] = '^'; arr[i+1][j+1] = 'v';
				B -= 2;
			}
		}

	} else {
		if (N&1) {for (int i = 0; i+1 < M && A; i += 2) {arr[N-1][i] = '<'; arr[N-1][i+1] = '>'; --A;}}
		if (M&1) {for (int i = 0; i+1 < N && B; i += 2) {arr[i][M-1] = '^'; arr[i+1][M-1] = 'v'; --B;}}
		
		for (int i = 0; i < N/2 * 2; i += 2) {
			for (int j = 0; j < M/2 * 2; j += 2) {
				if (A > 0) {
					arr[i][j] = '<'; arr[i][j+1] = '>'; --A;
					if (A) {arr[i+1][j] = '<'; arr[i+1][j+1] = '>'; --A;}
				} else if (B > 0) {
					arr[i][j] = '^'; arr[i+1][j] = 'v'; --B;
					if (B) {arr[i][j+1] = '^'; arr[i+1][j+1] = 'v'; --B;}
				}
			}
		}
	}
	

	if (A == 0 && B == 0) {
		print("YES");
		F0R(i, N) {
			F0R(j, M) cout << arr[i][j];
			cout << endl;
		}
	} else {
		print("NO");
	}
}
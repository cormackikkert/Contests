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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	
	vi ans;

	int pos = 0;
	while (ans.size() < N) {
		for (int x : {2, 3, 4, 5, 6, 8, 9, 10, 12, 14, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30}) {
			ans.push_back(pos + x);
		}
		pos += 30;
	}
	
	int addTo = 20;
	while (ans.size() > N) {
		ans[addTo--] += ans[ans.size() - 1];
		ans.pop_back();
	}

	if (N == 3) ans = {497, 634, 591};
	if (N == 4) ans = {934, 116, 159, 213};
	if (N == 5) ans = {355, 112, 939, 934, 216};
	if (N == 6) ans = {145, 868, 15, 68, 274, 590};
	if (N == 7) ans = {93, 6, 711, 730, 906, 8, 912};
	if (N == 8) ans = {560, 891, 407, 784, 429, 278, 470, 867};
	if (N == 9) ans = {924, 591, 602, 366, 430, 256, 21, 952, 352};
	if (N == 10) ans = {715, 99, 939, 202, 506, 201, 495, 14, 143, 586};
	if (N == 11) ans = {612, 512, 501, 568, 561, 332, 336, 162, 465, 814, 981};
	if (N == 12) ans = {308, 330, 993, 676, 786, 734, 712, 342, 51, 840, 916, 404};
	if (N == 13) ans = {76, 412, 766, 350, 927, 724, 550, 526, 417, 576, 522, 242, 980};
	if (N == 14) ans = {676, 604, 766, 763, 866, 730, 777, 32, 148, 850, 86, 102, 674, 948};
	if (N == 15) ans = {108, 644, 284, 766, 536, 952, 143, 339, 432, 254, 6, 93, 288, 672, 159};
	if (N == 16) ans = {960, 520, 326, 330, 164, 594, 285, 772, 68, 654, 868, 276, 498, 297, 831, 891};
	if (N == 17) ans = {444, 126, 770, 999, 360, 778, 692, 252, 685, 502, 417, 150, 128, 608, 254, 374, 441};
	if (N == 18) ans = {914, 8, 694, 356, 375, 882, 426, 6, 682, 861, 136, 954, 309, 902, 939, 918, 980, 62};
	if (N == 19) ans = {434, 133, 542, 303, 123, 390, 60, 170, 15, 738, 460, 334, 597, 700, 910, 962, 954, 330, 965};
	if (N == 20) ans = {334, 214, 315, 254, 678, 802, 906, 473, 264, 396, 553, 253, 700, 160, 948, 339, 279, 68, 515, 789};
	if (N == 21) ans = {408, 843, 946, 753, 590, 706, 424, 819, 712, 42, 626, 897, 878, 886, 765, 531, 472, 476, 818, 504, 632};
	if (N == 22) ans = {261, 399, 209, 972, 422, 268, 38, 6, 814, 82, 597, 995, 124, 960, 537, 159, 420, 147, 902, 411, 747, 430}; 

	for (int x : ans) {
		cout << x << " ";
	}
	
	cout << endl;
}
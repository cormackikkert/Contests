#include<cstdio>
#include<algorithm>
#define N_ 201000
using namespace std;
int n;
struct point {
	int A, B;
	bool operator<(const point &p)const {
		return A - B < p.A - p.B;
	}
}w[N_];
long long M = 1e18, S;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &w[i].A, &w[i].B);
		S += w[i].A;
		if (w[i].B < w[i].A) {
			M = min(w[i].B*1ll, M);
		}
	}
	if (M > 1e15)printf("0\n");
	else {
		printf("%lld\n", S - M);
	}
}
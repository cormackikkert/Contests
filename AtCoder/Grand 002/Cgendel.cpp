#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 100*1000+5;

int n;
ll l, a[maxn];

int main() {
    scanf("%d%lld", &n, &l);
    for (int i = 0; i < n; i++) scanf("%lld", a+i);
    for (int i = 0; i < n-1; i++) {
        if (a[i] + a[i+1] >= l) {
            printf("Possible\n");
            for (int j = 0; j < i; j++) printf("%d\n", j+1);
            for (int j = n-2; j > i; j--) printf("%d\n", j+1);
            printf("%d\n", i+1);
            return 0;
        }
    }
    printf("Impossible\n");
}

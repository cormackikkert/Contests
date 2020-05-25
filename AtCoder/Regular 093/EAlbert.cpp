#include <bits/stdc++.h>
using namespace std;
 
int A, B;
bool b[105][105];
 
int main() {
	scanf("%d%d", &A, &B);
 
	printf("100 100\n");
 
	for (int i = 0; i < 50; ++i) fill(b[i], b[i]+100, 1);
 
	int x = 0, y = 0;
	while (--A) {
		b[y][x] = 0;
		x += 2; if (x == 100) x = 0, y += 2;
	}
 
	x = 0, y = 99;
	while (--B) {
		b[y][x] = 1;
		x += 2; if (x == 100) x = 0, y -= 2;
	}
 
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (b[i][j]) printf("#");
			else printf(".");
		}
		printf("\n");
	}
}
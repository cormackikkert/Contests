#include <bits/stdc++.h>
using namespace std;
int r = 100;
int c = 100;
char grid[120][120];
void assignrow(int i)
{
	for (int j = 0; j < c; j++) grid[i][j] = '.';
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	assignrow(0);
	bool swapped = false;
	if (a < b)
	{
		swapped = 1;
		swap(a, b);
	}
	a--;
	b--;
	for (int i = 2; i < r && b; i+=2)
	{
		assignrow(i);
		b--;
		if (!b) a--;
		for (int j = 1; j < c-1 && b; j+=2)
		{
			b--;
			grid[i-1][j] = '.';
		}
	}
	while (a)
	{
		int x, y;
		x = rand()%r;
		y = rand()%c;
		if (!x || !y || x == r-1 || y == c-1) continue;
		bool works = 1;
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (grid[x+i][y+j]) works = 0;
			}
		}
		if (works)
		{
			a--;
			grid[x][y] = '.';
		}
	}	
	printf("%d %d\n", r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (!swapped)
			{
				if (grid[i][j] == '.') printf(".");
				else printf("#");
			}
			else
			{
				if (grid[i][j] != '.') printf(".");
				else printf("#");
			}
		}
		printf("\n");
	}	
}
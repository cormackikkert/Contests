#include <bits/stdc++.h>

using namespace std;

int main() {
	int k, d;
	cin >> k >> d;
	int books = 1, tot = k;
	while (tot <= d) {
		k *= 2;
		tot += k;
		++books;
	}
	cout << books-1 << endl;
}

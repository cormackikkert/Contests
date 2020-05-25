/*
ID: cormac.1
LANG: C++
TASK: combo
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int circ_dist(int a, int b, int c) {
	if (abs(a - b) < c / 2) {
		return abs(a - b);
	} else {
		return c - abs(a - b);
	}
}
bool is_valid(int n1, int n2, int n3, int c1, int c2, int c3, int N) {
	return (circ_dist(n1, c1, N) <= 2 && circ_dist(n2, c2, N) <= 2 && circ_dist(n3, c3, N) <= 2);
}

int main() {
	ifstream fin ("combo.in");
	ofstream fout ("combo.out");
	
	int N, a1, b1, c1, a2, b2, c2;
	fin >> N >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (is_valid(i, j, k, a1, b1, c1, N) || is_valid(i, j, k, a2, b2, c2, N)) count++;
			}
		}
	}
	fout << count << endl;
}

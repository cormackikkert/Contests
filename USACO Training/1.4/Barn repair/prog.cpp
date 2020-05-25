/*
ID: cormac.1
LANG: C++
PROG: barn1
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

int M, S, C;

	
int main() {
	ifstream fin ("barn1.in");
	ofstream fout ("barn1.out");

	fin >> M >> S >> C;
	
	int s = S;
	int e = 0;
	
	bool stalls[S];
	int pos;
	
	for (int i = 0; i < S; i++) {
		stalls[i] = false;
	}
	for (int i = 0; i < C; i++) {
		fin >> pos;
		stalls[pos-1] = true;
		s = min(s, pos-1);
		e = max(e, pos-1);
	}
	int total = e - s + 1;
	
	int lo;
	int hi;
	
	int tLo;
	int tHi;
	
	for (int i = 0; i < M - 1; i++) {
		tLo = s;
		tHi = s;
		
		lo = s;
		hi = s;
		
		while (lo != e and hi != e) {
			while (stalls[lo] && lo < e) {
				lo++;
			}
			while ((!stalls[hi] || hi <= lo) && hi < e) {
				hi++;
			}
			if ((hi - lo) > (tHi - tLo)) {
				tHi = hi;
				tLo = lo;
			}
			lo = hi;
		}
	
		for (int j = tLo; j < tHi; j++) {
			stalls[j] = true;
		}
		total -= tHi - tLo;
	}
	fout << total << endl;
}

/*
ID: cormac.1
LANG: C++
TASK: skidesign
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	ifstream fin ("skidesign.in");
	ofstream fout ("skidesign.out");
	
	int N;
	fin >> N;
	
	int hills[N];
	
	for (int i = 0; i < N; i++) {
		fin >> hills[i];
	}
	
	int total = 100 * 100 * 1000;
	
	int cur_total, hi;
	
	for (int lo = 0; lo < 100 - 17; lo++) {
		hi = lo + 17;
		cur_total = 0;
		for (int hill : hills) {
			if (hill < lo) {
				cur_total += (hill - lo) * (hill - lo);
			} else if (hill > hi) {
				cur_total += (hill - hi) * (hill - hi);
			}
		}
		total = min(total, cur_total);
	}
	
	fout << total << endl;
}

/*
ID: cormac.1
LANG: C++
TASK: crypt1
*/

#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool is_valid(int number, vector<int> &allowed) {
	for (char c : to_string(number)) {
		if (count(allowed.begin(), allowed.end(), (int)c - 48) == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	ifstream fin ("crypt1.in");
	ofstream fout ("crypt1.out");
	
	int N;
	fin >> N;
	
	vector<int> allowed (N);
	for (int i = 0; i < N; i++) {
		fin >> allowed[i];
	}
	
	int count = 0;
	int A, B, C, D, E;
	
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			for (int c = 0; c < N; c++) {
				for (int d = 0; d < N; d++) {
					for (int e = 0; e < N; e++) {
						A = allowed[a];
						B = allowed[b];
						C = allowed[c];
						D = allowed[d];
						E = allowed[e];
						
						int num1 = (A * 100 + B * 10 + C) * E;
						int num2 = (A * 100 + B * 10 + C) * D;
						
						if (num1 > 999 || num2 > 999) {
							continue;
						}
						if (is_valid(num1, allowed) && is_valid(num2, allowed) && is_valid(num1 + 10 * num2, allowed)) {
							count++;
						}
					}
				}
			}
		}
	}
	
	fout << count << endl;
}

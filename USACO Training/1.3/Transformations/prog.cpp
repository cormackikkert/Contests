/*
 ID: cormac.1
 LANG: C++
 TASK: transform
 */
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> grid) {
	int N = grid.size();
	vector<vector<int>> rotate (N);
	for (int y = 0; y < N; y++) {
		vector<int> temp (N);
		for (int x = 0; x < N; x++) {
			temp[x] = grid[x][y];
		}
		rotate[N-y-1] = temp;
	}
	return rotate;
}

vector<vector<int>> reflect(vector<vector<int>> grid) {
	int N = grid.size();
	vector<vector<int>> reflect (N);
	for (int y = 0; y < N; y++) {
		vector<int> temp (N);
		for (int x =0; x<N; x++) {
			temp[x] = grid[y][N-x-1];
		}
		reflect[y] = temp;
	}
	return reflect;
}

bool equal(vector<vector<int>> grid1, vector<vector<int>> grid2) {
	int N = grid1.size();
	for (int y = 0; y < N; y++) {
		 for (int x = 0; x < N; x++) {
			 if (grid1[y][x] != grid2[y][x]) return false;
		 }
	}
	return true;
}

int main() {
	ofstream fout ("transform.out");
	ifstream fin ("transform.in");
	
	int N;
	fin >> N;

	vector<vector<int>> before (N);
	vector<vector<int>> after (N);
	
	for (int i=0; i<N; i++) {
		string line;
		fin >> line;
		vector<int> temp (N);
		for (int j=0; j<N; j++) {
			temp[j] = (line[j] == '@') ? 1 : 0;
		}
		before[i] = temp;
	}
	for (int i=0; i<N; i++) {
		string line;
		fin >> line;
		vector<int> temp (N);
		for (int j=0; j<N; j++) {
			temp[j] = (line[j] == '@') ? 1 : 0;
		}
		after[i] = temp;
	}
		
	if (equal(rotate(rotate(rotate(before))), after)) {
		fout << 1;
	} else if (equal(rotate(rotate(before)), after)) {
		fout << 2;
	} else if (equal(rotate(before), after)) {
		fout << 3;
	} else if (equal(reflect(before), after)) {
		fout << 4;
	} else if (equal(rotate(reflect(before)), after) ||
			   equal(rotate(rotate(reflect(before))), after) ||
			   equal(rotate(rotate(rotate(reflect(before)))), after)) {
		fout << 5;
	} else if (equal(before, after)) {
		fout << 6;
	} else {
		fout << 7;
	}
	fout << "\n";
	
	return 0;
}

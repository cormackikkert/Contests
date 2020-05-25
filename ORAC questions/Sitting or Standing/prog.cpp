#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout("sitout.txt");
	ifstream fin("sitin.txt");
	
	int R, C, T;
	fin >> R >> C;
	fin >> T;
	if (T >= R*C) {
		fout << R * C << " " << T - R * C << endl;
	} else {
		fout << T << " " << 0 << endl;
	}
}

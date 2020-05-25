/*
 ID: cormac.1
 LANG: C++
 TASK: namenum
 */
 
 #include <iostream>
 #include <fstream>
 #include <string>
 
using namespace std;
 
string dict[5000];
int dict_length;
bool flag = false;
 
bool in_dict(string value) {
	int lo = 0;
	int hi = dict_length - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (dict[mid] < value) {
			lo = mid+1;
		} else if (dict[mid] > value) {
			hi = mid-1;
		} else {
			return true;
		}
	}
	return false;
}

string mapping[9][3] = {{"A", "B", "C"},
						{"D", "E", "F"},
						{"G", "H", "I"},
						{"J", "K", "L"},
						{"M", "N", "O"},
						{"P", "R", "S"},
						{"T", "U", "V"},
						{"W", "X", "Y"}};

ifstream fin ("namenum.in");
ofstream fout ("namenum.out");
						
void gen_numbers(string cur, string remove) {
	if (remove == "") {
		if (in_dict(cur)) {
			flag = true;
			fout << cur << "\n";
		}
	} else {
		int num = ((int) remove[0]) - 50;
		for (int i=0; i<3; i++) {
			gen_numbers(cur + mapping[num][i], remove.substr(1, remove.size() - 1));
		}
	}
}


int main() {
	ifstream dictin ("dict.txt");
	
	dict_length = 5000;
	
	for (int i=0; i<5000; i++) {
		dictin >> dict[i];
		if (dict[i] == "") dict_length = min(dict_length+1, i);
	}
		
	string num_name;
	fin >> num_name;
	
	gen_numbers("", num_name);
	
	if (flag == false) {
		fout << "NONE\n";
	}
	
	return 0;
}

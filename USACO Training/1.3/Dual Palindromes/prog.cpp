/*
ID: cormac.1
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

string values = "0123456789ABCDEFGHIJ";

string tobase(int number, int base) {
	string result = "";
	
	int length = (number != 0) ? log(number) / log(base) : 0;
	int value;
	
	for (int i = length; i >= 0; i--) {
		value = number / pow(base, i);
		number -= value * pow(base, i);
		result += values[value];
	}
	
	return result;
}

bool isPalindrome(string number) {
	for (unsigned int i = 0; i < number.length(); i++) {
		if (number[i] != number[number.length() - i - 1]) {
			return false;
		}
	}
	return true;
}	
	


int main() {
	ifstream fin ("dualpal.in");
	ofstream fout ("dualpal.out");
	int N, S;
	int count;
	fin >> N >> S;
	while (N > 0) {
		S++;
		count = 0;
		for (int base = 2; base <= 10; base++) {
			if (isPalindrome(tobase(S, base))) count++;
		}
		
		if (count >= 2) {
			fout << S << endl;
			N--;
		}
	}
}

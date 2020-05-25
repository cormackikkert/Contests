/*
ID: cormac.1
LANG: C++
TASK: palsquare
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
	ifstream fin ("palsquare.in");
	ofstream fout ("palsquare.out");
		
	int B;
	fin >> B;
	
	for (int N = 1; N <= 300; N++) {
		if (isPalindrome(tobase(N * N, B))) fout << tobase(N, B) << " " << tobase(N * N, B) << endl;
	}
	return 0;
}



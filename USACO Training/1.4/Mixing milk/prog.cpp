/*
ID: cormac.1
LANG: C++
TASK: milk
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

struct farm {
	int quantity;
	int price;
};

bool comp(farm &f1, farm &f2) {
	return (f1.price < f2.price);
}

int main() {
	ifstream fin ("milk.in");
	ofstream fout ("milk.out");
	int N, M;
	fin >> N >> M;
	
	farm farms[M];
	
	farm temp;
	for (int i = 0; i < M; i++) {
		fin >> temp.price >> temp.quantity;
		farms[i] = temp;
	}
	
	sort(farms, farms+M, comp);
	
	int totalCost = 0;
	
	int num;
	for (int i = 0; i < M; i++) {
		num = min(N, farms[i].quantity);
		totalCost += farms[i].price * num;
		N -= num;
		if (N == 0) {
			break;
		}
	}
	
	fout << totalCost << endl;
}

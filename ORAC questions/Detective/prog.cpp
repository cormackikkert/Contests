#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout("detectiveout.txt");
	ifstream fin("detectivein.txt");
	int N, M;
	fin >> N >> M;
	
	list<int> cla[N];
	list<int> sam[N];
	list<int> opp[N];
	list<int> t[N];
	
	for (int i = 0; i < M; i++) {
		int A, B, T;
		fin >> A >> B >> T;
		switch (T) {
			case 1:
				sam[A-1].push_front(B-1);
				sam[B-1].push_front(A-1);
				break;
			case 2:
				opp[A-1].push_front(B-1);
				opp[B-1].push_front(A-1);
				break;
			case 3:
				cla[A-1].push_front(B-1);
				if (t[B-1] != -1) {
					sam[A-1].push_front(t[B-1]);
					sam[T[B-1]].push_front(A-1);
				} else {
					t[B-1] = A-1;
				}
				break;
		}
	}
	
}

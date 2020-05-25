/*
ID: cormac.1
LANG: C++
TASK: wormhole
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int total = 0;

int N;

bool has_loop(int wormholes[][2], int connections[]) {
	int sx, sy, px, py;
	for (int s_hole = 0; s_hole < N; s_hole++) {
		sx = wormholes[s_hole][0];
		sy = wormholes[s_hole][1];
		
		px = sx;
		py = sy;
		
		while (true) {
			int tel = -1;
			for (int hole = 0; hole < N; hole++) {
				if (py == wormholes[hole][1] && px < wormholes[hole][0])
					if ((tel == -1) || (wormholes[hole][0] < wormholes[tel][0]))
						tel = hole;
			}
			
			if (tel == -1) break;
			
			px = wormholes[connections[tel]][0];
			py = wormholes[connections[tel]][1];		
			
			if (px == sx && py == sy) return true;
		}
	}
	return false;
}

void calculate_solutions(int wormholes[][2], int connections[]) {
	
	int s_vertex = N;
	for (int i = 0; i < N; i++) {
		if (connections[i] == -1) {
			s_vertex = i;
			break;
		}
	}
	
	if (s_vertex == N) {
		if (has_loop(wormholes, connections)) total++;
		return;
	}
		
	for (int e_vertex = s_vertex + 1; e_vertex < N; e_vertex++) {
		if (connections[e_vertex] != -1) continue;
		connections[s_vertex] = e_vertex;
		connections[e_vertex] = s_vertex;
		calculate_solutions(wormholes, connections);
		connections[e_vertex] = -1;
		connections[s_vertex] = -1;
	}
}

int main() {
	ifstream fin ("wormhole.in");
	ofstream fout ("wormhole.out");
	fin >> N;
	int wormholes[N][2];
	int connections[N];
	
	for (int i = 0; i < N; i++) {
		fin >> wormholes[i][0] >> wormholes[i][1];
		connections[i] = -1;
	}
	
	calculate_solutions(wormholes, connections);
	fout << total << endl;
}

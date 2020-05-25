/*
ID: cormac.1
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

int main() {
	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");
	
	int N;
	fin >> N;

	pair<int, int> times[N];

	int A, B;
	for (int i = 0; i < N; i++) {
		fin >> A >> B;
		times[i] = make_pair(A, B);
	}
	
	sort(times, times+N);
	
	int event_start_time = times[0].first;
	int event_end_time = times[0].second;
	int longest_time = 0;
	int longest_time_no_milking = 0;
	
	for (auto t : times) {
		if (t.first <= event_end_time) {
			event_end_time = max(event_end_time, t.second);
		} else {
			longest_time = max(longest_time, event_end_time - event_start_time);
			event_start_time = t.first;
			longest_time_no_milking = max(longest_time_no_milking, event_start_time - event_end_time);
			event_end_time = t.second;
		}
	}
	longest_time = max(longest_time, event_end_time - event_start_time);
	fout << longest_time << " " << longest_time_no_milking << "\n";
}

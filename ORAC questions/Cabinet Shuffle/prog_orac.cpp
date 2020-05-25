#include <bits/stdc++.h>
using namespace std;

template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
    while (true) {
        int K = rand() % 20 + 1;
        int N = K + rand() % 20 + 1;
        vector<bool> isChair (N+1);
        vector<bool> isPerson (N+1);

        for (int i = 0; i < K; ++i) {
            int ind = rand() % N + 1; 
            if (isChair[ind]) {--i; continue;}
            isChair[ind] = true;
        }
        
        for (int i = 0; i <= K; ++i) {
            int ind = rand() % N + 1; 
            if (isPerson[ind]) {--i; continue;}
            isPerson[ind] = true;
        }

        // cout << "Trying: " << to_string(isChair) << " " << to_string(isPerson) << endl;
        int l = 1;
        int h = N;
        stack<int> peopleStack;
        int personCount = 1;
        int oppPersonCount = K+1;
        int firstPerson = -1;
        while (l <= h) {
            if (isPerson[l]) {
                peopleStack.push(personCount++);
            } 
            if (isChair[l]) {
                int chairStack = 0;
                while (peopleStack.empty()) {
                    if (isChair[h]) ++chairStack;
                    if (isPerson[h]) {
                        if (chairStack == 0) {
                            peopleStack.push(oppPersonCount--); --h; break;
                        } else {
                            --chairStack; --oppPersonCount;
                        } 
                    }
                    --h;
                }
                if (firstPerson == -1) firstPerson = peopleStack.top();
                peopleStack.pop();
            }
            ++l;
        }
    }
    // cout << firstPerson << "\n" << peopleStack.top() << endl;
}
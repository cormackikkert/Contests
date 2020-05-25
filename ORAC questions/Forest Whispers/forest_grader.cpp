/*
 * Sample grader for Forest Whispers.
 */

#include "forest.h"

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

static bool is_permutation(const vector<int> &v);

static const unsigned int K[] = {1000, 2000, 115000};

static bool is_permutation(const vector<int> &v);

int main() {
    int T;
    scanf("%d",&T);

    int N, M;
    scanf("%d %d",&N,&M);

    vector<int> A, B;
    for (int i=0;i<M;i++) {
        int a, b;
        scanf("%d %d",&a,&b);
        A.push_back(a);
        B.push_back(b);
    }

    auto P = austin(T, N, M, A, B);
    if (P.size() > K[T-1]) {
        fprintf(stderr,
                "Austin whispered a sequence of length %lu, which is too long! (max length = %u for subtask %u)\n",
                P.size(), K[T-1], T);
        return 1;
    }

    if (!is_permutation(P)) {
        fprintf(stderr, "The sequence Austin whispered was not a permutation.\n");
        return 1;
    }

    int Q;
    scanf("%d",&Q);

    vector<int> qA, qB;
    for (int i=0;i<Q;i++) {
        int a, b;
        scanf("%d %d",&a,&b);
        qA.push_back(a);
        qB.push_back(b);
    }

    auto answers = breanna(T, N, P, Q, qA, qB);
    if (answers.size() != Q) {
        fprintf(stderr,
                "Breanna returned an incorrect number of answers: %lu returned, but Q = %d expected\n",
                answers.size(), Q);
        return 1;
    }

    for (auto a: answers) {
        printf("%d\n", a);
    }

    fprintf(stderr, "Austin whispered a valid permutation of length %lu\n", P.size());

    return 0;
}

static bool is_permutation(const vector<int> &v) {
    if (v.empty()) {
        return true;
    }

    vector<int> sorted;
    for (auto e: v) {
        sorted.push_back(e);
    }
    sort(sorted.begin(), sorted.end());

    if (sorted[0] != 0) {
        return false;
    }

    for (int i=1;i<sorted.size();i++) {
        if (sorted[i] != sorted[i-1] + 1) {
            return false;
        }
    }
    return true;
}

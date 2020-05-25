#include "flip.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int cards = getC();
    int placements [cards/2];
    fill(placements, placements + cards/2, -1);
    
    int check = 1;
    while (check <= cards) {
        char seen = faceup(check);
        if (placements[seen - 'A'] != -1) {
            faceup(placements[seen - 'A']);
            ++check; continue;
        } else {
            placements[seen - 'A'] = check;
            char seen2 = faceup(check + 1);
            if (seen2 == seen) {
                check = check + 2; continue;
            } else if (placements[seen2 - 'A'] != -1) {
                ++check; continue;
            } else {
                placements[seen2 - 'A'] = check + 1;
                check += 2; continue;
            }
        }
    }
}
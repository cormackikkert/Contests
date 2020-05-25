    int t2 = probs[i].first;
            t2 -= B * reqhard; t2 -= A * reqeasy;
            if (t1 >= 0) {
                int extra_easy = min(t2 / A, alleasy - reqeasy);
                t2 -= A * extra_easy;
                int extra_hard = min(t2 / B, allhard - reqhard);
                best = max(best, extra_easy + extra_hard + reqeasy + reqhard);
            }
//  greedy_sol1.cpp
//
//  Problem setter's code for "Greedy Generosity"
//  SPPC Divisional 2017
//
//  The problem is intended to be soluble by straight brute force, so
//  this implements such an approach, with no attempt at all to save time

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> coin_values {1, 2, 5, 10, 20, 50};
    int n_coin_values = 6;
    
    vector<int> standard_level(n_coin_values);
    for(int i = 0; i < n_coin_values; i++) cin >> standard_level[i];
    
    
    vector<int> current_level(standard_level);
    int extra_paid = 0;
    
    int T = 0; // T transactions
    cin >> T;
    
    // Process transactions
    for(int t = 0; t < T; t++)
    {
        int sale = 0;
        cin >> sale;
        int paid = 0;
        for(int coin = 0; coin < n_coin_values; coin++)
        {
            int n_this_value = 0;
            cin >> n_this_value;
            paid += n_this_value * coin_values[coin];
            current_level[coin] += n_this_value;
        }
        int change_needed = paid - sale;
        
        // If change needed, work up amounts until can pay according to greedy
        // principle required
        if(change_needed > 0)
        {
            bool solved = false;
            for(int change = change_needed; !solved; change++)
            {
                solved = true;
                int change_left = change;
                vector<int> coins_used(n_coin_values);
                for(int c = n_coin_values - 1; c >= 0; c--)
                {
                    while(change_left >= coin_values[c])
                    {
                        coins_used[c]++;
                        change_left -= coin_values[c];
                    }
                    if(coins_used[c] > current_level[c])
                    {
                        solved = false;
                    }
                }
                
                // If can pay as required, do so
                if(solved)
                {
                    extra_paid += change - change_needed;
                    
                    if(change == change_needed)
                    {
                        for(int i = 0; i < n_coin_values; i++)
                        {
                            current_level[i] -= coins_used[i];
                        }
                    }
                    else // Extra payout, reset stocks
                    {
                        current_level = standard_level;
                    }
                    
                }
            }
        }
    }
    
    // Output answer
    cout << extra_paid << endl;
    
    return 0;
}

/**
 * You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
 * You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
 * Return the maximum profit you can achieve. You may choose to not make any transactions, 
 * in which case the profit would be 0.
 */

#include <vector>
#include <algorithm>

using namespace std; 

int maxProfit(vector<int>& prices) {
    vector<int> prefixMaxEarnings(prices.size()); 
    prefixMaxEarnings.at(prices.size() - 1) = prices.at(prices.size() - 1); 
    int maxProfit = 0;

    for (int i = prices.size() - 2; i >= 0; i--) {
        prefixMaxEarnings.at(i) = max(prefixMaxEarnings.at(i+1), prices.at(i));
    }

    for (int i = 0; i < prices.size(); i++) {
        int toTest = prefixMaxEarnings.at(i) - prices.at(i);
        maxProfit = max(toTest, maxProfit);  // since maxProfit initialized at 0, don't need to check that toTest < 0
    }

    return maxProfit; 
}
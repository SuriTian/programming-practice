/**
 * Given an integer array nums and an integer k, return the k most frequent elements within the array.
 * The test cases are generated such that the answer is always unique.
 * You may return the output in any order.
 */

#include<vector>
#include<map>
#include<algorithm>
using namespace std; 

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> hashSet; // element, frequency
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        hashSet[nums[i]]++;
    }

    vector<pair<int,int>> v(hashSet.begin(), hashSet.end());

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.second > b.second; // sort by frequency descending
    });

    for (auto&pair : v) {
        result.push_back(pair.first);
    }

    vector<int> acc_result;

    for (int i = 0; i < k; i++) {
        acc_result.push_back(result.at(i));
    }

    return acc_result;

    
    

}
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


/**
 * Use the bucket sort algorithm to create n buckets, grouping numbers based on their frequencies from 1 to n. 
 * Then, pick the top k numbers from the buckets, starting from n down to 1.
 */
vector<int> topKFrequentWBucketSort(vector<int>& nums, int k) {
    // Build a frequency map that counts how many times each number appears.
    map<int, int> freqMap; // num, freq
    for (int i = 0; i < nums.size(); i++) {
        freqMap[nums.at(i)]++; 
    }

    // Create a list of groups freq, where freq[i] will store all numbers that appear exactly i times.
    vector<vector<int>> freq(nums.size() + 1); // remember that frequency can be num.size(), so we need one more so the last index lands on that 

    // For each number and its frequency in the map, add the number to freq[frequency].
    for (auto& pair : freqMap) {
        freq[pair.second].push_back(pair.first); 
    }

    // Initialize an empty result list.
    vector<int> result;

    int count = 0; 
    int index = freq.size() - 1; 

    while (count < k) {
        for (int i = 0; i < freq[index].size(); i++) {
            if (count >= k) {
                return result;
            }

            result.push_back(freq[index][i]);
            count++;
        }

        index--;
    }

    return result; 

}
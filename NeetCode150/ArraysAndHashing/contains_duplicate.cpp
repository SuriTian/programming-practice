/**
 * Given an integer array nums, return true if any 
 * value appears more than once in the array, otherwise return false.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// naive, O(n^2) time complexity solution
bool hasDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums.at(i) == nums.at(j)) return true;
        }
    }
    
    return false; 
}

// interesting O(nlogn) solution
// VER WITH A BUG!!!
/**
 * When nums is empty, an error occurs because nums.size() returns size_t, an UNSIGNED INT
 * When you do 0 - 1 the unsigned int wraps around to a very large number
 */
bool hasDuplicate2(vector<int>& nums) {
    sort(nums.begin(), nums.end()); 

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums.at(i) == nums.at(i+1)) return true; // .at eventually accesses index out of bounds if nums is empty
    }

    return false; 
}

bool hasDuplicate2Correct(vector<int>& nums) {
    if (nums.size() < 2) return false; 

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums.at(i) == nums.at(i + 1)) return true;
    }

    return false; 
}

// O(n), O(n) time and space
bool useHashSets(vector<int>& nums) {
    unordered_set<int> hashSet; // use C++'s built in hashmaps!!!!!!!

    for (int i = 0; i < nums.size(); i++) {
        if (hashSet.find(nums.at(i)) != hashSet.end()) return true;
        hashSet.insert(nums.at(i));
    }

    return false; 
}

bool useHashSetsLength(vector<int>& nums) {
    unordered_set<int> hashSet;
    for (auto elmt : nums) {
        hashSet.insert(elmt);  // dups are ignored
    }

    return (hashSet.size() != nums.size());
}

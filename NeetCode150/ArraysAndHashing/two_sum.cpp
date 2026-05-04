#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std; 

/**
 * Given an array of integers nums and an integer target, return the indices i and j 
 * such that nums[i] + nums[j] == target and i != j.
 * You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
 * Return the answer with the smaller index first.
 */

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashSet; // value, indice 
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        hashSet[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
        int toFind = target - nums[i]; 

        if (hashSet.find(toFind) != hashSet.end() && i != hashSet[toFind]) {
            result = {i, hashSet[toFind]};
            return result; 
        }
    }

}


vector<int> twoSumSorted(vector<int>& nums, int target) {
    vector<pair<int,int>> sortedArr;

    for (int i = 0; i < nums.size(); i++) {
        sortedArr.push_back({nums[i], i}); 
    }

    sort(sortedArr.begin(), sortedArr.end()); 

    int i = 0, j = sortedArr.size() - 1;

    while (i < j) {
        int curr = sortedArr[i].first + sortedArr[j].first;

        if (curr == target) {
            return {min(sortedArr[i].second, sortedArr[j].second), max(sortedArr[i].second, sortedArr[j].second)};
        }
        else if (curr < target) {
            i++;
        }
        else {
            j--;
        }
    }

    return {};

}

int main() {

}
/**
 * Given an array of integers numbers that is sorted in non-decreasing order.
 * Return the indices (1-indexed) of two numbers, [index1, index2], 
 * such that they add up to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.
 * There will always be exactly one valid solution.
 * Your solution must use O(1) additional space
 */

#include<vector>

using namespace std; 

vector<int> twoSum(vector<int>& numbers, int target) {
    int front = 0;
    int back = numbers.size() - 1;
    vector<int> result; 

    while (front < back) {
        int sum = numbers.at(front) + numbers.at(back);

        if (sum == target) {
            result.push_back(front + 1); // one indexed for some reason
            result.push_back(back + 1);
            
            return result; // can also return {front, back}
        }
        else if (sum < target) {
            front++; 
        }
        else {
            back--; 
        }
    }
}
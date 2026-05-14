/**
 * Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].
 * Each product is guaranteed to fit in a 32-bit integer.
 * Follow-up: Could you solve it in O(n) time without using the division operation?
 */

#include<vector>
#include<string>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prefix(nums.size());
    vector<int> suffix(nums.size()); 
    vector<int> result; 

    prefix.at(0) = 1;
    suffix.at(nums.size() - 1) = 1;

    for (int i = 1; i < nums.size(); i++) {
        prefix.at(i) = prefix.at(i - 1) * nums.at(i - 1); 
    }

    for (int i = nums.size() - 2; i >= 0; i--) {
        suffix.at(i) = suffix.at(i + 1) * nums.at(i + 1); 
    }

    for (int i = 0; i < nums.size(); i++) {
        result.push_back(prefix.at(i) * suffix.at(i));
    }

    return result;
}
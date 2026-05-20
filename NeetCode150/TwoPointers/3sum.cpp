/**
 * Given an integer array nums, return all the triplets 
 * [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.
 * The output should not contain any duplicate triplets. You may return the output and the triplets in any order.
 */

#include <vector>
#include <algorithm>

using namespace std; 

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result; 
    sort(nums.begin(), nums.end()); 

    for (int i = 0; i < nums.size(); i++) { // nums[i] = - (nums[j] + nums[k]) 
        if (nums[i] > 0) break; // in order for 3sum = 0, there has to be a negative number somewhere. 
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = -nums[i]; 
        int j = i + 1; // removes dups possibility
        int k = nums.size() - 1; 

        while (j < k) {
            if (j == i) {
                j++;
            }
            else if (k == i) {
                k--;
            }
            else if (nums[j] + nums[k] == target) {
                result.push_back({nums[i], nums[j], nums[k]}); // the search continues even after one is found, because diff pair could occur
                j++;
                k--; 
                while (j < k && nums[j] == nums[j - 1]) j++; // ensure to skip all dups 
            }
            else if (nums[j] + nums[k] < target) {
                j++;
            }
            else {
                k--;
            }
        }
    }

    return result;
}
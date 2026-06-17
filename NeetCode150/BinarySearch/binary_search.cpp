#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi = nums.size() - 1;
        int lo = 0;

        while (hi >= lo) {
            int curr = (hi + lo) / 2;
            if (nums[curr] == target) {
                return curr;
            }
            else if (nums[curr] > target) {
                hi = curr - 1; 
            }
            else {
                lo = curr + 1; 
            }
        } 

        return -1;
    }
};

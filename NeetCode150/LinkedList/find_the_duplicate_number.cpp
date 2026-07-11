#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // the idea is to not change any numbers, but negate the positions instead

        for (int i = 0; i < nums.size(); i++) {
            int idxToSearch = abs(nums[i]) - 1;

            if (nums[idxToSearch] < 0) return abs(nums[i]);
            else {
                nums[idxToSearch] *= -1; 
            }
        }
    }
};

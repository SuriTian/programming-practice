#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; 
        int r = nums.size() - 1; 

        while (l < r) {
            int m = (r - l) / 2 + l;

            if (nums[m] > nums[r]) {
                // move l until we have nums[l] < nums[r]
                l = m + 1;
            }
            else {
                r = m; 
            }
        }

        int pivot = l; 

        l = 0;
        r = pivot - 1;

        while (l <= r) {
            int m = (r - l) / 2 + l;

            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        l = pivot;
        r = nums.size() - 1;

        while (l <= r) {
            int m = (r - l) / 2 + l;

            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        return -1; 
    }

};

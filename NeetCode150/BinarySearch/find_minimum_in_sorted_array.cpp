#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = nums.at(0); 

        while (l <= r) {
            int mid = (r - l) / 2 + l;

            if (nums.at(l) < nums.at(r)) {
                // normal
                ans = min(ans, nums.at(l));
                break; 
            }

            ans = min(ans, nums.at(mid));

            // left segment
            if (nums.at(l) <= nums.at(mid)) {
                // go right
                l = mid + 1; 
            }
            else {
                // go left
                r = mid - 1;
            }
        }

        return ans; 
    }
};

#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> windowStore;
        vector<int> output; 

        // ensure deque is monotonically decreasing 
        for (int i = 0; i < k; i++) {
            if (windowStore.empty() || nums[i] <= windowStore.back().first) {
                windowStore.push_back({nums[i], i});
            }
            else {
                while (!windowStore.empty() && windowStore.back().first < nums[i]) {
                    windowStore.pop_back(); 
                }

                windowStore.push_back({nums[i], i}); 
            } 
        }

        output.push_back(windowStore.front().first);

        // i is the last element of the window
        for (int i = k; i < nums.size(); i++) {
            if (windowStore.front().second == i - k) {
                windowStore.pop_front(); 
            }

            if (nums[i] <= windowStore.back().first) {
                windowStore.push_back({nums[i], i});
            }
            else {
                while (!windowStore.empty() && windowStore.back().first < nums[i]) {
                    windowStore.pop_back(); 
                }

                windowStore.push_back({nums[i], i}); 
            }

            output.push_back(windowStore.front().first); 
        }

        return output;
    }
};

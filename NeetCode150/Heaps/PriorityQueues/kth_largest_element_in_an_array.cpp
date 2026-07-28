#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> minHeap;

        for (int i = 0; i < nums.size(); i++) {
            if (minHeap.size() < k) {
                minHeap.push(-1 * nums[i]); // makes it minHeap 
            }
            else {
                if (minHeap.top() > -1 * nums[i]) {
                    minHeap.pop();
                    minHeap.push(nums[i] * -1); 
                }
            }
        }

        return minHeap.top() * -1; 
    }
};

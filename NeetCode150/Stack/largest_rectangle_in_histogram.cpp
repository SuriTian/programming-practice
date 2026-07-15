#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // strat: keep an increasing stack, with index of the bar 
        // area = height[i] * (right - left + 1)

        stack<int> bars; // need to keep increasing
        int maxArea = 0; 

        for (int i = 0; i <= heights.size(); i++) { // i == n to trigger the pops and maxArea update
            // keep the stack "monotonically incr"
            // when we meet a higher bar, keep popping and calculating height
            while (!bars.empty() && (i == heights.size() || heights[bars.top()] >= heights[i])) {
                int height = heights[bars.top()];
                bars.pop();
                int width = bars.empty() ? i : i - bars.top() - 1; // first case primarily for when we've popped everything, so the width is naturally where i was
                maxArea = max(maxArea, height * width);
            }

            bars.push(i);
        }

        return maxArea; 
    }
};

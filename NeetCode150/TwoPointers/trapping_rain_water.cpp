/**
 * You are given an array of non-negative integers height which represent an elevation map. 
 * Each value height[i] represents the height of a bar, which has a width of 1.
 * Return the maximum area of water that can be trapped between the bars.
 */


#include<vector>
#include<algorithm>

using namespace std; 

int trap(vector<int>& height) {
    // equation of water trapped at i: min(height[left], height[right]) - currheight => currheight = height[i]

    if (height.size() == 0) return 0;

    vector<int> prefix(height.size());
    vector<int> suffix(height.size());
    int area = 0;

    prefix[0] = height[0];
    suffix[height.size() - 1] = height[height.size() - 1]; 

    for (int i = 1; i < height.size(); i++) {
        prefix[i] = max(prefix[i-1], height[i]);
    }
    for (int i = height.size() - 2; i >= 0; i--) {
        suffix[i] = (max(suffix[i+1], height[i]));
    }
    for (int i = 0; i < height.size(); i++) {
        area += min(prefix[i], suffix[i]) - height[i]; 
    }

    return area; 
}
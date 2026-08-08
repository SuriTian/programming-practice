#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res; 

    void dfs(vector<int>& nums, vector<int>& curr, int index) {
        if (curr.size() > nums.size()) {
            return; 
        }

        if (index >= nums.size()) {
            res.push_back(curr); 
            return;
        }

        curr.push_back(nums[index]);
        dfs(nums, curr, index + 1);
        curr.pop_back(); 
        dfs(nums, curr, index + 1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        dfs(nums, curr, 0);
        return res;
    }
};

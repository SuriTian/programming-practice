#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res; 

    void dfs(vector<int>& nums, int target, int index, int currSum, vector<int> curr) {
        if (currSum == target) {
            res.push_back(curr);
            return; 
        }
        
        if (currSum > target || index >= nums.size()) {
            return; 
        }

        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            dfs(nums, target, i, currSum + nums[i], curr);
            curr.pop_back();  
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr; 
        dfs(nums, target, 0, 0, curr);

        return res;
    }
};

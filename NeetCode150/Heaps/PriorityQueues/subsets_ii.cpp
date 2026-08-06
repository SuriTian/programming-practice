#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res; 
    void dfs(vector<int>& nums, vector<int> curr, int i) {
        res.push_back(curr); 
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue; 
            }

            curr.push_back(nums[j]); 
            dfs(nums, curr, j + 1); 
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, {}, 0);
        return res;
    }
};

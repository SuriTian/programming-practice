#include <vector>
#include <algorithm>

using namespace std;

class Solution {
   public:
    vector<vector<int>> res;

    void dfs(vector<int>& candidates, vector<int>& curr, int index, int sum, int target) {
        if (sum == target) {
            res.push_back(curr);
            return;
        }

        if (sum > target || index == candidates.size()) {
            return;
        }

        curr.push_back(candidates[index]);
        dfs(candidates, curr, index + 1, sum + candidates[index], target);
        curr.pop_back();

        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) index++;

        dfs(candidates, curr, index + 1, sum, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(candidates, curr, 0, 0, target);
        return vector<vector<int>>(res.begin(), res.end());
    }
};

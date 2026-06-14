#include <map>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hashSet; 
        vector<int> ans; 

        for (auto& elmt: nums) {
            hashSet[elmt]++; 
        }

        vector<pair<int, int>> v(hashSet.begin(), hashSet.end());

        sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second > b.second; });
                
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};

#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> store;  // val, idx
        vector<int> res(temperatures.size()); 

        for (int i = 0; i < temperatures.size(); i++) {
            int curr = temperatures.at(i);

            if (store.empty() || store.top().first >= curr) {
                store.push({curr, i});
            }
            else {
                while (!store.empty() && store.top().first < curr ) {
                    res.at(store.top().second) = i - store.top().second; 
                    store.pop(); 
                }

                store.push({curr, i});
            }
        }

        return res; 
    }
};

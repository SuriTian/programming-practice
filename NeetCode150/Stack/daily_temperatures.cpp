#include <vector>
#include <stack>

using namespace std; 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> tempStack;
        vector<int> tempStore(temperatures.size(), 0);
        
        for (int i = 0; i < temperatures.size(); i++) {
            while(!tempStack.empty() && temperatures[i] > tempStack.top().first) {
                auto pair = tempStack.top(); 
                tempStack.pop(); 
                tempStore[pair.second] = i - pair.second; 
            }

            tempStack.push({temperatures[i], i});
        }

        return tempStore;
    }
};

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

// dynamic proramming ver 
class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            if (i == temperatures.size() - 1) res[i] = 0; 
            else if (temperatures[i] < temperatures[i + 1]) {
                res[i] = 1; 
            }
            else {
                int toCheck = res[i + 1] + i + 1; 

                // >= is possible because we can have same temperature in the future, so we need to skip it
                while (toCheck < temperatures.size() && temperatures[i] >= temperatures[toCheck]) {
                    if (toCheck < res[toCheck] + toCheck) {
                        toCheck = res[toCheck] + toCheck;
                    }
                    else {
                        break;
                    }
                } 

                res[i] = temperatures[toCheck] > temperatures[i] ? toCheck - i : 0; 
            }
        }

        return res;
    }
};

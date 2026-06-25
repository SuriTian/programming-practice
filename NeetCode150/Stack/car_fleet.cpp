#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> myStack; 
        int carFleets;

        vector<pair<int, int>> sortedCars;

        for (int i = 0; i < position.size(); i++) {
            sortedCars.push_back({position[i], speed[i]});
        } 

        // sort by descending position 
        sort(sortedCars.begin(), sortedCars.end(), [](auto & a, auto & b) {
            return a.first > b.first; 
        });

        for (int i = 0; i < sortedCars.size(); i++) {
            double time = (target - sortedCars[i].first) / (double) sortedCars[i].second;

            // if time of current car <= previous fleet making car, then it joins the fleet
            // otherwise, as shown in the if statement, it makes a new fleet
            if (myStack.empty() || time > myStack.top()) {
                myStack.push(time);
            }
        }

        return myStack.size(); 
    }
};

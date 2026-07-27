#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> maxHeap; 

        for (int i = 0; i < points.size(); i++) {
            double currDist = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));

            if (maxHeap.size() >= k) {
                int x1 = maxHeap.top().second[0];
                int y1 = maxHeap.top().second[1];
                double distTop = sqrt(pow(x1, 2) + pow(y1, 2));

                if (distTop > currDist) {
                    maxHeap.pop();
                    maxHeap.push({currDist, points[i]});
                }
            }
            else {
                maxHeap.push({currDist, points[i]});
            }
        }

        vector<vector<int>> res; 
        for (int i = 0; i < k; i++) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop(); 
        }

        return res;
    }
};

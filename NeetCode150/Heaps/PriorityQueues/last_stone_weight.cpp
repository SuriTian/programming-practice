#include <queue>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap; 

        if (stones.size() == 0) return 0;
        if (stones.size() == 1) return stones[0]; 

        for (int i = 0; i < stones.size(); i++) {
            maxHeap.push(stones[i]);
        }

        while (maxHeap.size() > 1) {
            int top1 = maxHeap.top();
            maxHeap.pop();
            int top2 = maxHeap.top();
            maxHeap.pop(); 

            if (top1 != top2) {
                int leftover = abs(top1 - top2);
                maxHeap.push(leftover); 
            }
        }

        if (maxHeap.empty()) return 0;

        return maxHeap.top(); 
    }
};

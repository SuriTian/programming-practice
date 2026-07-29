#include <vector>
#include <queue>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;  
        priority_queue<int> maxHeap;
        deque<pair<int, int>> q; // count, time we want to add back to maxHeap 
        unordered_map<int, int> hashSet; // hashset of frequency 

        for (int i = 0; i < tasks.size(); i++) {
            hashSet[tasks[i]]++; 
        }

        for (const auto &elmt : hashSet) {
            maxHeap.push(elmt.second); 
        } 

        while (maxHeap.size() > 0 || q.size() > 0) {
            time++; 

            if (!maxHeap.empty()) {
                // process task 
                int count = maxHeap.top() - 1;
                maxHeap.pop(); 

                if (count > 0) {
                    q.push_back({count, time + n}); 
                }
            }

            // put queue things back to heap
            if (!q.empty() && q.front().second == time) {
                int putBack = q.front().first; 
                maxHeap.push(putBack); 
                q.pop_front();
            }
        }

        return time; 
    }
};

#include <queue>
#include <vector>

using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k; 
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); 
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val); 
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top(); 
    }
};

// solution #2
class KthLargest {
public:
    priority_queue<int> minHeap; 
    int k;
    
    KthLargest(int k, vector<int>& nums) {
       this->k = k; 
       for (int i = 0; i < nums.size(); i++) {
            minHeap.push(-1 * nums[i]);
            
            if (minHeap.size() > k) {
                minHeap.pop(); 
            }
       } 
    }
    
    int add(int val) {
        minHeap.push(-1 * val);

        if (minHeap.size() > k) {
            minHeap.pop();
        } 

        return minHeap.top() * -1;
    }
};

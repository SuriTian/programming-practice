#include <unordered_set>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited; 

        ListNode* curr = head;
        
        while (curr) {
            if (visited.find(curr) != visited.end()) {
                return true; 
            }

            visited.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};


class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head; 

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};

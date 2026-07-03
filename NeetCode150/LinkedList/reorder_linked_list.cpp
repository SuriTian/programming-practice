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
    void reorderList(ListNode* head) {
        ListNode* fast = head; 
        ListNode* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next; 
        }
        
        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr; // disconnects the ptr

        // reverse second half 
        while (second) {
            ListNode* temp = second->next; 
            second->next = prev;
            prev = second;
            second = temp; 
        }

        ListNode* first = head;
        second = prev;

        while (second) {
            // connects first curr, second, first next 
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2; 
        }
    }
};

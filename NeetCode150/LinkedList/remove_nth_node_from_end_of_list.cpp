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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pointToRes = new ListNode(0, head);
        ListNode* far = head;
        ListNode* nth = pointToRes;

        for (int i = 0; i < n; i++) {
            far = far->next; 
        } 

        while (far) {
            far = far->next;
            nth = nth->next; 
        }

        nth->next = nth->next->next; 

        return pointToRes->next; // can't directly point to head because what if everything is removed
    }
};

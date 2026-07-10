struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = l1;
        ListNode* curr2 = l2;
        ListNode* res = new ListNode();
        ListNode* toreturn = res; 
        int carry = 0;

        while (curr || curr2) {
            if (curr && !curr2) {
                curr2 = new ListNode(0);
            }
            else if (curr2 && !curr) {
                curr = new ListNode(0);
            }

            int val = (curr->val + curr2->val + carry) % 10;
            carry = (curr->val + curr2->val + carry) / 10; 

            res->next = new ListNode(val); 

            curr = curr->next;
            curr2 = curr2->next;
            res = res->next;
        }    

        if (carry != 0) res->next = new ListNode(carry); 

        return toreturn->next; 
    }
};

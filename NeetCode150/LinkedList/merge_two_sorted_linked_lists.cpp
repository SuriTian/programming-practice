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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode temp(0); // immediate node where val = 0, next is nullptr
        ListNode* curr = &temp;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        // add the remaining that have not been added
        if (list1) {
            curr->next = list1;
        }
        else {
            curr->next = list2;
        }

        return temp.next; 
    }
};

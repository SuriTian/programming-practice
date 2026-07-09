#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToCopy; // <old ll, deep copy ll>
        oldToCopy[NULL] = NULL;

        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val); // make a new node with value
            oldToCopy[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            Node* copy = oldToCopy[curr];
            copy->next = oldToCopy[curr->next];
            copy->random = oldToCopy[curr->random];
            curr = curr->next;
        }

        return oldToCopy[head];

    }
};

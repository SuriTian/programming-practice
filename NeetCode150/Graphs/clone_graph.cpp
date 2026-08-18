#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs(Node* curr, unordered_map<Node*, Node*> & hashSet) {
        if (hashSet.find(curr) != hashSet.end()) {
            return hashSet[curr];
        }

        Node* newNode = new Node(curr->val);
        hashSet[curr] = newNode;

        for (int i = 0; i < curr->neighbors.size(); i++) {
            newNode->neighbors.push_back(dfs(curr->neighbors[i], hashSet));
        }

        return hashSet[curr];
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr; 
        unordered_map<Node*, Node*> hashSet; 
        dfs(node, hashSet); 

        return hashSet[node];
    }
};

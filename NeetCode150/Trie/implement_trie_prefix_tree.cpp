#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool endOfWord = false;
};

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for (auto c : word) {
            // not in hashmap alr
            if (curr->children.find(c) == curr->children.end()) {
                TrieNode* newNode = new TrieNode();
                curr->children[c] = newNode;
            }

            // go to next
            curr = curr->children[c]; 
        }

        curr->endOfWord = true; 
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for (auto c : word) {
            // not in hashmap alr
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }

            // go to next
            curr = curr->children[c]; 
        }

        return curr->endOfWord == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (auto c : prefix) {
            // not in hashmap alr
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }

            // go to next
            curr = curr->children[c]; 
        }

        return true;
    }
};

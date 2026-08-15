#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool endOfWord = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (auto c : word) {
            // did not find the character
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode(); 
            }

            curr = curr->children[c];
        }

        curr->endOfWord = true; 
    }
    
    bool dfs(TrieNode* root, int idx, string word) {
        TrieNode* curr = root;
        for (int i = idx; i < word.size(); i++) {
            char c = word[i];

            if (c == '.') {
                for (auto child : curr->children) {
                    if (dfs(child.second, i + 1, word)) {
                        return true;
                    }
                }

                return false;
            }

            // did not find the character
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }

            curr = curr->children[c];
        }

        return curr->endOfWord == true; 

    }

    bool search(string word) {
        TrieNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            // special case, skip the character
            if (c == '.') {
                for (auto child : curr->children) {
                    if (dfs(child.second, i + 1, word)) {
                        return true;
                    }
                }

                return false;
            }

            // did not find the character
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }

            curr = curr->children[c];
        }

        return curr->endOfWord == true; 
    }
};

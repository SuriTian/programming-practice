#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> res; 

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res; 
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) return;

        // first node at the new depth
        if (res.size() == depth) {
            res.push_back(node->val); 
        }

        dfs(node->right, depth + 1); // right child first
        dfs(node->left, depth + 1);
    }
};

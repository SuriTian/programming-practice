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
    int count = 0; 
    int res;

    void dfs(TreeNode* node, int k) {
        if (!node) return;

        dfs(node->left, k);

        count++; 
        if (count == k) {
            res = node->val;
            return;
        }

        dfs(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res; 
    }
};

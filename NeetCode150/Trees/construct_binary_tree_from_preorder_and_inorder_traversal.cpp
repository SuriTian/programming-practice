#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 

// preorder is root left right
// inorder is left root right

class Solution {
public:
    TreeNode* dfs(vector<int>& preorder, unordered_map<int, int>& inorderIndex, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inorderIndex[rootVal];
        int leftSize = mid - inStart;

        root->left = dfs(preorder, inorderIndex, preStart + 1, preStart + leftSize, inStart, mid - 1);
        root->right = dfs(preorder, inorderIndex, preStart + leftSize + 1, preEnd, mid + 1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hashSet; // value, index
        for (int i = 0; i < inorder.size(); i++) {
            hashSet[inorder[i]] = i;
        }

        return dfs(preorder, hashSet, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
 
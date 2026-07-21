#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; 

        queue<TreeNode*> store; 
        store.push(root);

        while(!store.empty()) {
            int qLen = store.size();
            vector<int> level;

            for (int i = 0; i < qLen; i++) {
                TreeNode* currNode = store.front(); 
                store.pop();
                if (currNode) {
                    level.push_back(currNode->val);
                    store.push(currNode->left);
                    store.push(currNode->right);
                }
            }

            if (!level.empty()) res.push_back(level); 
        }

        return res; 

    }
};

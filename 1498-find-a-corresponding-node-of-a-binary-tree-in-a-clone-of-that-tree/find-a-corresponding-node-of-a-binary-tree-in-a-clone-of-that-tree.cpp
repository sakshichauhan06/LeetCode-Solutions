/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;

    Solution() : ans(nullptr) {}

    void find(TreeNode* root, int k) {
        if (root == nullptr) {
            return;
        }
        if (root->val == k) {
            ans = root;
            return;
        }
        find(root->left, k);
        find(root->right, k);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (target == nullptr) {
            return nullptr;
        }
        int k = target->val;
        find(cloned, k);

        return ans;
    }
};

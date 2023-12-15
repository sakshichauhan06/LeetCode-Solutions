/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int l = getHeight(root->left) + 1;
        int r = getHeight(root->right) + 1;

        return max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        if(abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }

        return false;
    }
};
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
    bool checkUni(TreeNode* root, int k) {
        if(root == nullptr) {
            return true;
        } else if(root->val != k) {
            return false;
        }
        return checkUni(root->left, k) && checkUni(root->right, k);
    }

    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        return checkUni(root, root->val);
    }
};
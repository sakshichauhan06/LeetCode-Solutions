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
    bool validate(TreeNode* root, long long l, long long r) {
        if(root == nullptr) {
            return true;
        }
        if(root->val < r && root->val > l) {
            return validate(root->left, l, root->val) && validate(root->right, root->val, r);
        } else {
            return false; 
        }
    }

    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max = 1000000000000;
        return validate(root, min, max);
    }
};
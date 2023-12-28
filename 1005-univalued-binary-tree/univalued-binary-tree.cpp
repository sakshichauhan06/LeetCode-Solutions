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
    bool flag = true;
    void dfs(TreeNode* root, int k) {
        if(root == nullptr) {
            return;
        }
        if(root->val != k) {
            flag = false;
            return;
        } 
        dfs(root->left, k);
        dfs(root->right, k);
    }

    bool isUnivalTree(TreeNode* root) {
        int k = root->val;
        dfs(root, k);

        return flag;
    }
};
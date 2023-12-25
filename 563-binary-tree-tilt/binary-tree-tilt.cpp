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
    int sum = 0;
    int dfs(TreeNode* root) {
        int a = (root->left ? dfs(root->left) : 0);
        int b = (root->right ? dfs(root->right) : 0);
        sum += abs(a - b);
        return a + b + root->val;
    }

    int findTilt(TreeNode* root) {
        if(root != nullptr) {
            dfs(root);
        }
        return sum;
    }
};
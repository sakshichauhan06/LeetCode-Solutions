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
    unordered_map<TreeNode*, int> mp;
    int dfs(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        if(mp.count(root)) {
            return mp[root];
        }
        int withRoot = root->val;
        if(root->left) {
            withRoot += dfs(root->left->left) + dfs(root->left->right);
        }
        if(root->right) {
            withRoot += dfs(root->right->left) + dfs(root->right->right);
        }
        int withoutRoot = dfs(root->left) + dfs(root->right);
        return mp[root] = max(withRoot, withoutRoot);
    }

    int rob(TreeNode* root) {
        return dfs(root);
    }
};
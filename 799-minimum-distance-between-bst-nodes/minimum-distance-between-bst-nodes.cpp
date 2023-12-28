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
    void dfs(TreeNode* root, vector<int> &v) {
        if(root == nullptr) {
            return;
        }
        v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        sort(v.begin(), v.end());
        int n = v.size();
        int mini = INT_MAX;

        for(int i = 1; i < n; i++) {
            int diff = abs(v[i] - v[i - 1]);
            mini = min(mini, diff);
        }

        return mini;
    }
};
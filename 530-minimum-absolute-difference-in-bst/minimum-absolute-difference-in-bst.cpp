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
    void traverse(TreeNode* root, vector<int> &v) {
        if(root == nullptr) {
            return;
        }
        traverse(root->left, v);
        v.push_back(root->val);
        traverse(root->right, v);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        traverse(root, v);

        int n = v.size();
        int mini = INT_MAX;

        for(int i = 1; i < n; i++) {
            int diff = abs(v[i] - v[i - 1]);
            mini = min(mini, diff);
        }

        return mini;
    }
};
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
    void traverse(TreeNode* root, multiset<int> &s) {
        if(root == nullptr) {
            return;
        }
        s.insert(root->val);
        traverse(root->left, s);
        traverse(root->right, s);
    }

    int getMinimumDifference(TreeNode* root) {
        multiset<int> s;
        traverse(root, s);

        vector<int> v(s.begin(), s.end());
        int n = v.size();
        int mini = INT_MAX;

        for(int i = 1; i < n; i++) {
            int diff = abs(v[i] - v[i - 1]);
            mini = min(mini, diff);
        }

        return mini;
    }
};
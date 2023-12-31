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
    void getSum(TreeNode* root, vector<vector<int>> &ans, vector<int> &v, int &targetSum, int curSum) {
        if(root == nullptr) {
            return;
        }

        curSum += root->val;
        v.push_back(root->val);

        if (!root->left && !root->right && curSum == targetSum) {
            ans.push_back(v);
        }

        getSum(root->left, ans, v, targetSum, curSum);
        getSum(root->right, ans, v, targetSum, curSum);

        v.pop_back(); //backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        getSum(root, ans, v, targetSum, 0);

        return ans;
    }
};

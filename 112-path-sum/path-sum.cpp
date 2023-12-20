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
    void dfs(TreeNode* root, int sum, int target, vector<int> &v) {
        if(root != nullptr && root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            v.push_back(sum);
            return;
        }
        if(root != nullptr) {
            sum += root->val;
            dfs(root->left, sum, target, v);
            dfs(root->right, sum, target, v);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        vector<int> v;
        dfs(root, 0, targetSum, v);

        for(auto it : v) {
            if(it == targetSum) {
                return true;
            }
        }

        return false;
    }
};
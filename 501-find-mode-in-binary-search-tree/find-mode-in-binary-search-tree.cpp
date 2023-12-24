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
    void dfs(TreeNode* root, unordered_map<int, int> &mp) {
        if(root == nullptr) {
            return;
        }
        mp[root->val]++;
        dfs(root->left, mp);
        dfs(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int> ans;

        dfs(root, mp);
        int maxi = 0;
        int num = -1;

        for(auto it : mp) {
            if(maxi < it.second) {
                maxi = it.second;
            }
        }

        for(auto it : mp) {
            if(it.second == maxi) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
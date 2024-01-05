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
    unordered_map<int, int> count;
    int maxi = 0;
    int dfs(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int k = dfs(root->left) + dfs(root->right) + root->val;
        maxi = max(maxi, ++count[k]);
        return k;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> v;
        dfs(root);

        for(auto &it : count) {
            if(it.second == maxi) {
                v.push_back(it.first);
            }
        }

        return v;
    }
};
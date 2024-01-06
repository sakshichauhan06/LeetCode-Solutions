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

    void depth(TreeNode* root, int count, vector<pair<int, int>> &vp) {
        if(root == nullptr) {
            return;
        }
        if(!root->left && !root->right) {
            vp.push_back({count, root->val});
        }
        depth(root->left, count + 1, vp);
        depth(root->right, count + 1, vp);
    }

    int findBottomLeftValue(TreeNode* root) {
        
        vector<pair<int, int>> vp;
        int count = 0;
        depth(root, 0, vp);
        int maxi = INT_MIN;
        int ans = -1;

        for(auto it : vp) {
            if(it.first >  maxi) {
                maxi = it.first;
                ans = it.second;
            }
        }
        
        return ans;
    }
};
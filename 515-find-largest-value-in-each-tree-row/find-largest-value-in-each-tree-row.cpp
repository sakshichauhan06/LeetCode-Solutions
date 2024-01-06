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
    void bfs(TreeNode* root, vector<int> &ans) {
        if(root == nullptr) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;

        while(!q.empty()) {
            int len = q.size();
            int maxi = INT_MIN;
            for(int i = 0; i < len; i++) {
                temp = q.front();
                q.pop();
                maxi = max(maxi, temp->val);
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            ans.push_back(maxi);
        }

    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        bfs(root, ans);

        return ans;
    }
};
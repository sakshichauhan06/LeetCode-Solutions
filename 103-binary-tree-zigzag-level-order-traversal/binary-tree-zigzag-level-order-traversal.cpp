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
    void bfs(TreeNode* root, vector<vector<int>> &ans) {
        if(root == nullptr) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while(!q.empty()) {
            int len = q.size();
            vector<int> v;
            for(int i = 0; i < len; i++) {
                TreeNode* temp = q.front();
                v.push_back(temp->val);
                q.pop();
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            if(flag) {
                reverse(v.begin(), v.end());
                ans.push_back(v);
                flag = false;
            } else {
                ans.push_back(v);
                flag = true;
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<vector<int>> ans;
        bfs(root, ans);

        return ans;
    }
};
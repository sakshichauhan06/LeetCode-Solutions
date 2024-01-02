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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;

        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                vector<int> v;
                temp = q.front();
                q.pop();

                if(i == len - 1) {
                    ans.push_back(temp->val);
                }

                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
        }
        

        return ans;
    }
};
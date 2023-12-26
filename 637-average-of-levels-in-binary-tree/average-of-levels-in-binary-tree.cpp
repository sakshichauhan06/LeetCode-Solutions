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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<double> ans;
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();
            double sum = 0;
            for(int i = 0; i < len; i++) {
                temp = q.front();
                sum += temp->val;
                q.pop();
                if(temp->left != nullptr) {
                    q.push(temp->left);
                }
                if(temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            sum = sum / len;
            ans.push_back(sum);
        }

        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int target, int &flag, vector<TreeNode*> &v, vector<TreeNode*> &ans) {
        if(root == nullptr || flag == 1) {
            return;
        }
        v.push_back(root);
        if(root->val == target) {
            flag = 0;
        }
        if(!root->left && !root->right && flag == 0) {
            ans = v;
            flag = 1;
        }
        dfs(root->left, target, flag, v, ans);
        dfs(root->right, target, flag, v, ans);
        v.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root || q == root) {
            return root;
        }
        vector<TreeNode*> v1, v2, ans1, ans2;
        int flag = -1;
        dfs(root, p->val, flag, v1, ans1);
        flag = -1;
        dfs(root, q->val, flag, v2, ans2);

        int i = 0, j = 0;
        int n = ans1.size(), m = ans2.size();
        TreeNode* k = nullptr;

        if(ans1 == ans2) {
            while(i < n && j < m) {
                if(ans1[i] == p || ans1[i] == q) {
                    k = ans1[i];
                    break;
                }
                i++;
                j++;
            }
        } else {
            while(i < n && j < m) {
                if(ans1[i]->val == ans2[j]->val) {
                    k = ans1[i];
                }
                i++;
                j++;
            }
        }

        return k;
    }
};
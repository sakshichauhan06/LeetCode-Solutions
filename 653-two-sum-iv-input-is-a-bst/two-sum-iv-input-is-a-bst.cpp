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
    void inorder(TreeNode* root, vector<int> &v1) {
        if(root == nullptr) {
            return;
        }
        inorder(root->left, v1);
        v1.push_back(root->val);
        inorder(root->right, v1);
    }

    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr || (root && !root->left && !root->right)) {
            return false;
        }

        vector<int> v1, v2;
        inorder(root, v1);
        int n = v1.size();
        for(int i = n - 1; i >= 0; i--) {
            v2.push_back(v1[i]);
        }

        int i = 0, j = 0;
        while(i < n && j < n) {
            if(v1[i] + v2[j] == k && v1[i] != v2[j]) {
                return true;
            } else if(v1[i] + v2[j] < k) {
                i++;
            } else {
                j++;
            }
        }
        return false;
    }
};
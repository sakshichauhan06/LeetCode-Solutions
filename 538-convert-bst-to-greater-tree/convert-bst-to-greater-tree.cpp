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
    void inorder(TreeNode* root, vector<int> &v) {
        if(root == nullptr) {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    void putValues(TreeNode* root, stack<int> &s) {
        if(root == nullptr || s.empty()) {
            return;
        }
        putValues(root->left, s);
        root->val = s.top();
        s.pop();
        putValues(root->right, s);
    }

    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) {
            return nullptr;
        }

        vector<int> v;
        inorder(root, v);
        reverse(v.begin(), v.end());
        int n = v.size();
        stack<int> s;
        s.push(v[0]);

        for(int i = 1; i < n; i++) {
            v[i] += v[i - 1];
            s.push(v[i]);
        }
        
        putValues(root, s);

        return root;
    }
};
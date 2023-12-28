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

    void insertNodes(TreeNode* root, vector<int> &v, int i, int n) {
        if(root == nullptr || i >= n) {
            return;
        }
        TreeNode* t(new TreeNode(v[i]));
        root->left = nullptr;
        root->right = t;
        insertNodes(t, v, i + 1, n);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int n = v.size();

        TreeNode* newroot(new TreeNode(v[0]));
        insertNodes(newroot, v, 1, n);

        return newroot;

    }
};
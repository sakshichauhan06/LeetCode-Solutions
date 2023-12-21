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
private:
    int diameter;
public:
    int longestPath(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int left_path = longestPath(root->left);
        int right_path = longestPath(root->right);

        diameter = max(diameter, left_path + right_path);

        return max(left_path, right_path) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // max depth of left-subtree and right-subtree
        if(root == nullptr) {
            return 0;
        }
        diameter = 0;
        longestPath(root);

        return diameter;
    }
};
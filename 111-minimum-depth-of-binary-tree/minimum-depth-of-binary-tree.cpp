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
    int getMini(TreeNode* root, int len) {
        if(root == nullptr) {
            return 0;
        } else if(root != nullptr && root->left == nullptr && root->right != nullptr) {
            return getMini(root->right, len + 1);
        } else if(root != nullptr && root->left != nullptr && root->right == nullptr){
            return getMini(root->left, len + 1);
        } else if(root != nullptr && root->left == nullptr && root->right == nullptr) {
            return len;
        } else if(root != nullptr) {
            return min(getMini(root->left, len + 1), getMini(root->right, len + 1));
        }
        return len;
    }

    int minDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int ans = getMini(root, 1);

        return ans;
    }
};
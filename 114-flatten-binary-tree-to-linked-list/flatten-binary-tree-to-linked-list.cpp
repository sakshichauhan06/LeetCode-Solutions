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
    void flatten(TreeNode* root) {
        TreeNode* newNode = root;

        while(newNode) {
            if(newNode->left) {
                TreeNode* pre = newNode->left;
                while(pre->right) {
                    pre = pre->right;
                }
                pre->right = newNode->right;
                newNode->right = newNode->left;
                newNode->left = nullptr;
            }
            newNode = newNode->right;
        }
    }
};
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
    TreeNode* firstElement = nullptr;
    TreeNode* secondElement = nullptr;
    TreeNode* prevElement = nullptr;

    void inorder(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        inorder(root->left);
        
        if(prevElement) {
            if(firstElement == nullptr && prevElement->val >= root->val) {
                firstElement = prevElement;
            }
        }
        if(firstElement != nullptr && prevElement->val >= root->val) {
            secondElement = root;
        }

        prevElement = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        int temp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = temp;

        return;
    }
};
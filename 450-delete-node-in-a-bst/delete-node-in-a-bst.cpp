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
    TreeNode* getMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key); 
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); 
        } else { // we found our key !!!
            // Case 1: Is a leaf node
            if (!root->left && !root->right) {
                delete root;
                root = nullptr;
            }
            // Case 2: One child
            else if (root->left == nullptr) {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            // Case 3: Two children
            else {
                TreeNode* temp = getMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};

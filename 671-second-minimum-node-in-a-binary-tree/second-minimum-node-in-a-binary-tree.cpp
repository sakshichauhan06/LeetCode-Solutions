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
    int mini = INT_MAX;
    int secMini = INT_MAX;
    bool flag = false;

    void findSec(TreeNode* root, int mini) {
        if(root == nullptr) {
            return;
        }
        if(root->val != mini) {
            secMini = min(secMini, root->val);
            if(secMini == INT_MAX) {
                flag = true;
            }
        }
        findSec(root->left, mini);
        findSec(root->right, mini);
    }

    void findMini(TreeNode* root) {
        if(root == nullptr) {
            return;
        } 
        mini = min(mini, root->val);
        findMini(root->left);
        findMini(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        findMini(root);
        findSec(root, mini);

        if(secMini == INT_MAX && !flag) {
            return -1;
        }

        return secMini;
    }
};
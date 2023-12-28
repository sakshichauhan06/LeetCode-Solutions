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
    int xd, yd, xp, yp;
    void depth(TreeNode* root, int x, int y, int dep, int par) {
        if(root == nullptr) {
            return;
        }
        if(root->val == x) {
            xd = dep;
            xp = par;
            return;
        }
        if(root->val == y) {
            yd = dep;
            yp = par;
            return;
        }
        depth(root->left, x, y, dep + 1, root->val);
        depth(root->right, x, y, dep + 1, root->val);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y) {
            return false;
        }
        depth(root, x, y, 0, 0);

        if(xd == yd && xp != yp) {
            return true;
        }

        return false;
    }
};
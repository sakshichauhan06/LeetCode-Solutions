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
    TreeNode* build(vector<int> &inorder, vector<int> &postorder, int &rootIdx, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int k = left;
        while(inorder[k] != postorder[rootIdx]) {
            k++;
        }
        rootIdx--;
        TreeNode* newNode = new TreeNode(inorder[k]);
        newNode->right = build(inorder, postorder, rootIdx, k + 1, right);
        newNode->left = build(inorder, postorder, rootIdx, left, k - 1);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx = postorder.size() - 1;
        return build(inorder, postorder, rootIdx, 0, inorder.size() - 1);
    }
};
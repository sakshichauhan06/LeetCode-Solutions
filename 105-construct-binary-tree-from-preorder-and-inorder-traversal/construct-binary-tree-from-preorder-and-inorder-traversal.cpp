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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIdx, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int k = left;
        while(inorder[k] != preorder[rootIdx]) {
            k++;
        }
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[k]);
        newNode->left = build(preorder, inorder, rootIdx, left, k - 1);
        newNode->right = build(preorder, inorder, rootIdx, k + 1, right);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size() - 1);
    }
};
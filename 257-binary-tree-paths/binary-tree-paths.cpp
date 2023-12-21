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
    void leafNode(TreeNode* root, string s, vector<string> &ans) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            int k = root->val;
            string temp = to_string(k);
            s += temp;
            ans.push_back(s);
            return;
        }
        int k = root->val;
        string temp = to_string(k);
        s += temp;
        s += "->";
        leafNode(root->left, s, ans);
        leafNode(root->right, s, ans);
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;

        leafNode(root, s, ans);

        cout<<s;

        return ans;
    }
};
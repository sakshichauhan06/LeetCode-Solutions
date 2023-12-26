class Solution {
public:
    void dfs(TreeNode* t1, TreeNode* t2,TreeNode* &root){
        if(!t1 && !t2) return;
        else if(t1 && !t2){
            TreeNode* node(new TreeNode(t1->val));
            root=node;
            dfs(t1->left,t2,root->left);
            dfs(t1->right,t2,root->right);
        }else if(t2 && !t1){
            TreeNode* node(new TreeNode(t2->val));
            root=node;
            dfs(t1,t2->left,root->left);
            dfs(t1,t2->right,root->right);
        }else{
            TreeNode* node(new TreeNode(t1->val+t2->val));
            root=node;
            dfs(t1->left,t2->left,root->left);
            dfs(t1->right,t2->right,root->right);
        }
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root(nullptr);
        dfs(t1,t2,root);
        return root;
    }
};
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
    int getMaxIndex(vector<int> &nums, int l, int h) {
        int idx = 0;
        int maxi = INT_MIN;
        for(int i = l; i <= h; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                idx = i;
            }
        }
        return idx;
    }

    TreeNode* construct(vector<int> &nums, int l, int h) {
        if(l > h) {
            return nullptr;
        }
        int i = getMaxIndex(nums, l, h);
        TreeNode* newnode = new TreeNode(nums[i]);
        newnode->left = construct(nums, l, i - 1);
        newnode->right = construct(nums, i + 1, h);
        return newnode;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return nullptr;
        }
        return construct(nums, 0, n - 1);
    }
};
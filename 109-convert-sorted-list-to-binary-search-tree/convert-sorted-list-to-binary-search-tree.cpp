/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void getV(ListNode* head, vector<int> &v) {
        if(head == nullptr) {
            return;
        }
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode* getBst(vector<int> &v, int l, int h) {
        if(l > h) {
            return nullptr;
        }
        int mid = l + (h - l) / 2;
        TreeNode* newNode = new TreeNode(v[mid]);
        newNode->left = getBst(v, l, mid - 1);
        newNode->right = getBst(v, mid + 1, h);

        return newNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        getV(head, v);
        int l = 0, h = v.size() - 1;
        return getBst(v, l, h);
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int height(Node* root) {
        if(root == nullptr) {
            return 0;
        }
        vector<int> v;
        
        for(int i = 0; i < root->children.size(); i++) {
            v.push_back(height(root->children[i]));
        }
        int temp = -1;
        
        for(int i = 0; i < v.size(); i++) {
            temp = max(temp, v[i]);
        }

        return temp + 1;

    }

    int maxDepth(Node* root) {
        if(root == nullptr) {
            return 0;
        }
        return height(root) + 1;
    }
};
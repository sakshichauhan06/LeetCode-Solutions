/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return head;
        }

        Node *temp = head;
        
        //mapping
        while(temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        //assigning radom pointers
        temp = head;
        while(temp) {
            if(temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // unconnect the original LL to our deep copy
        Node *newHead = head->next;
        Node *temp2 = head->next;
        temp = head;

        while(temp && temp2) {
            Node *curr = temp2->next;
            temp->next = curr;
            if(curr) {
                temp2->next = curr->next;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }

        return newHead;

    }
};
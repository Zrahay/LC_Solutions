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
        if(head == NULL) return NULL;

        

        map<Node*, Node*> mpp;

        Node* temp = head;
        while(temp != NULL){
            mpp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        Node* temp1 = head;
        while(temp1 != NULL){
            (mpp[temp1])->next = mpp[temp1->next];
            (mpp[temp1])->random = mpp[temp1->random];
            temp1 = temp1->next;
        }

        return mpp[head];
    }
};
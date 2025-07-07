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
        

        if (head == NULL)
            return NULL;

        Node* temp = head;
        Node* res = head;
        while (temp != NULL) {
            Node* node = new Node(temp->val);
            res = temp->next;
            temp->next = node;
            node->next = res;
            temp = temp->next->next;
        }

        

        temp = head;
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            temp = temp->next->next;
        }

        // Now we need to connect the next pointers

        Node* nodeis = new Node(-100);
        Node* nodehead = nodeis;
        Node* newhead = nodeis;
        temp = head;

        while(temp != NULL){
            newhead->next = temp->next;
            newhead = newhead->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }


        

        return nodehead->next;
    }
};
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL) return 0;
        if(head->next == NULL) return head;
        int n = len(head);
        int num_rotations = (k % n);
        int val = n - num_rotations;

        if((k % n) == 0) return head;
        // First find the last node
        ListNode* temp = head;

        int count = 0;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
        // Now find the new last node which is n - k
        ListNode* temp2 = head;
        count++;
        while(count != val){
            count++;
            temp2 = temp2->next;
        }
        ListNode* temp1 = temp2->next;
        head = temp1;
        temp2->next = NULL;

        return head;

    }

    int len(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        count++;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
            
        }

        return count;
    }
};
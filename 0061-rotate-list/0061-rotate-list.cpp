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


        while(num_rotations != 0){
            ListNode* temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            ListNode* temp1 = temp->next;
            temp->next = NULL;
            temp1->next = head;
            head = temp1;
            --num_rotations;
        }

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
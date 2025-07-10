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
    int getDecimalValue(ListNode* head) {
        if(head->next == NULL) return head->val;

        ListNode* temp = head;
        ListNode* newtemp = LLreverse(head); 

        int prod = 1;
        int ans = 0;

        ListNode* temp2 = newtemp;

        while(temp2 != NULL){
            ans += (temp2->val) * prod;
            prod *= 2;
           
           
            temp2 = temp2->next;
        }

        return ans;










    }

    ListNode* LLreverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* front = head;
        ListNode* temp1 = temp;
        if(head == NULL || head->next == NULL) return head;

        front = temp->next;
        temp = temp->next;
        temp1->next = NULL;
        while(front != NULL){
            front = temp->next;
            temp->next = temp1;
            temp1 = temp;
            temp = front;
        }

        ListNode* head2 = temp1;
        return head2;
    }


};
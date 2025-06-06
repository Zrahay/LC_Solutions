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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1000);

        ListNode* temp1 = dummy1;
        ListNode* temp2 = dummy2;
        ListNode* temp = head;

        while(temp != NULL){
            if(temp->val < x){
                temp1->next = temp;
                temp1 = temp;
                temp = temp->next;
                temp1->next = NULL;
            }
            else{
                temp2->next = temp;
                temp2 = temp;
                temp = temp->next;
                temp2->next = NULL;
            }

            
        }

        temp1->next = dummy2;

        ListNode* temp_final = dummy1;
        ListNode* temp_prefinal = temp_final;
        

        while(temp_final != NULL){
            if(temp_final->val != -1000){
                temp_prefinal = temp_final;
                temp_final = temp_final->next;
            }
            else{
                temp_final = temp_final->next;
                temp_prefinal->next = temp_final;
                break;
            }
        }
         return dummy1->next;

       
    }
};
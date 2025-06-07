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
    ListNode* oddEvenList(ListNode* head) {
        int len = sz(head);
        int count = 0;

        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1000);

        ListNode* temp1 = dummy1;
        ListNode* temp2 = dummy2;

        
        count++;
        while(temp != NULL){
            if(count % 2 != 0){
                temp1->next = temp;
                temp1 = temp;
                temp = temp->next;
                count++;
                temp1->next = NULL;
            }
            else{
                temp2->next = temp;
                temp2 = temp;
                temp = temp->next;
                count++;
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

    int sz(ListNode* head){
        ListNode* temp = head;
        int count = 0;

        if(head == NULL) return 0;

        if (head->next == NULL) return 1;
        count++;

        while(temp->next != NULL){
            temp = temp->next;
            count++;
        }

        return count;
    }

};
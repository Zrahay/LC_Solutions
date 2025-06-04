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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        int sum = 0;
        ListNode* temp1 = temp;
        temp = temp->next;
        
        while(temp){
            if(temp->val != 0 && temp->next != NULL){
                sum += temp->val;
                temp =  temp->next;
                continue;
            }
            else{
                count++;
                ListNode* insert = new ListNode(sum);
                sum = 0;
                temp = temp->next;
                if(count == 1){
                    head = insert;
                    temp1 = head;
                }
                else{
                    temp1->next = insert;
                    temp1 = insert;
                }
            }
        }

        return head;
    }
};
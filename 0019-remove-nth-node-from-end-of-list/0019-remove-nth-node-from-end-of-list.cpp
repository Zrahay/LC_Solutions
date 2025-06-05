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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = sz(head);
        int count = 0;
        ListNode* temp = head;
        count++;
        ListNode* temp1 = head;

        if(head->next == NULL){
            head = NULL;
            return head;
        }
        while(temp != NULL){
            if(n != (len - count + 1)){
                temp1 = temp;
                temp = temp->next;
                count++;
            }
            else{
                if(temp == head){
                    head= head->next;
                    break;
                }
                cout<<"We are here "<<len - count + 1<<"\n";
                ListNode* temp2 = temp;
                temp = temp->next;
                temp2->next = NULL;
                temp1->next = temp;
                break;
            }
        } 

        return head;
    }

    int sz(ListNode* head){
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
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
    ListNode* middleNode(ListNode* head) {
        int len = sz(head);
        int count = 1;
        int n;
        if(len % 2 == 0){
            n = (len / 2) + 1;
        }
        else n = (len / 2) + 1;
        ListNode* temp = head;
        
        
        ListNode* temp1 = head;

        if(head->next == NULL || head == NULL){
            return head;
        }

        while(temp != NULL){
            if(count != n){
                temp1 = temp;
                temp = temp->next;
                count++;
            }
            else{
                head = temp;
                temp1->next=NULL;
                cout<<temp->val<<"\n";
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
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
    ListNode* swapNodes(ListNode* head, int k) {

        if(head->next == NULL){
            return head;
        }
        int len = sz(head);
        int x = k;
        int y = len - k + 1;
        cout<<x<<"\n";
        cout<<y<<"\n";

        ListNode* temp = head;
        vector<ListNode*>v;
        int count = 0;
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;

        while(temp != NULL){
            count++;
            if(count == x){
                temp1 = temp;
            }
            if(count == y){
                temp2 = temp;
            }

            temp = temp->next;
            
        }
        swap(temp1->val, temp2->val);

    


        return head;
    }

    int sz(ListNode* head){
        int count = 0;

        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        return count;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
       ListNode* temp = node;
       ListNode* temp1 = node;

       while(temp->next != NULL){
        int val1 = temp->next->val;
        cout<<val1<<"\n";
        int cur = temp->val;
        swap(val1,cur);
        cout<<"Cur's value is "<<cur<<"\n";
        temp->val = cur;
        temp1 = temp;
        temp = temp->next;
       }
       temp1->next=NULL;
    }
};
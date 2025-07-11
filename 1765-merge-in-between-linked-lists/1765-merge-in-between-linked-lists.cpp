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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int n = sz(list1);
        int m = sz(list2);

        int count = 0;
        ListNode* temp = list1;
        count++;
        while(count < (a)){
            temp = temp->next;
            count++;
        }

        cout<<temp->val<<"\n";

        count = 0;
        count++;
        ListNode* temp1 = list1;
        while(count != (b + 1)){
            temp1 = temp1->next;
            count++;
        }
        cout<<"Temp 1 is -> "<<temp1->val<<"\n";

        temp->next = list2;
        temp = temp->next;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = temp1->next;

        return list1;


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
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;

        while(temp->next != NULL){
            int val1 = temp->val;
            ListNode* temp1 = temp;
            temp = temp->next;
            int val2 = temp->val;
            int ans = gcd(val1,val2);
            ListNode* insert = new ListNode(ans,temp);
            temp1->next = insert;
        }
        return head;
    }
};
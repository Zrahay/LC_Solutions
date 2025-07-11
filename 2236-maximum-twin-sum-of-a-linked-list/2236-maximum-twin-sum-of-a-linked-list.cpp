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
    int pairSum(ListNode* head) {
        int n = sz(head);

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp1 = LLreverse(slow);
        ListNode* newhead = temp1;
        int maxi = INT_MIN;
        ListNode* temp  = head;

        int count = 0;
        while(newhead != NULL){
            count++;
            maxi = max(temp->val + newhead->val, maxi);
            temp = temp->next;
            newhead = newhead->next;
        }

        return maxi;
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

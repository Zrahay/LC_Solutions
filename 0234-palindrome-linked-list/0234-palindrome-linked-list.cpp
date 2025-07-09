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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        int sz = len(head);

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(sz % 2 == 0){
            ListNode* newLL = LLreverse(slow);

            ListNode* newhead = newLL;

            ListNode* tempnew = head;
            while(newhead != NULL){
                if(tempnew->val != newhead->val) return false;

                tempnew = tempnew->next;
                newhead = newhead->next;
                cout<<"We are here"<<"\n";
            }
            return true;

        }

        ListNode* newLL = LLreverse(slow->next);
        ListNode* newhead = newLL;
        ListNode* tempnew = head;
        while(newhead != NULL){
            if(tempnew->val != newhead->val) return false;

                tempnew = tempnew->next;
                newhead = newhead->next;
        }

        return true;



    }

    int len(ListNode* head){
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
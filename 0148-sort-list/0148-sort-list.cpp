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
    ListNode* sortList(ListNode* head) {
        vector<int> val;

        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        while(temp != NULL){
            val.push_back(temp->val);
            temp = temp->next;
        }

        // Now we need to create a new Linked List from this

        // 4,2,1,3

        sort(val.begin(),val.end());

        ListNode* dummy1 = new ListNode(-1);

        ListNode* temp1 = dummy1;
        for(int i = 0 ;i < val.size(); i++){
            ListNode* newnode = new ListNode(val[i]);
            temp1->next = newnode;
            temp1 = newnode;
        }

        return dummy1->next;



    }
};
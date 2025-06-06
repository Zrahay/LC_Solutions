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
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;

        map<ListNode*,int>mpp;
        if(head == NULL|| head->next == NULL) return false;
        int i = 0;
        while(temp->next != NULL){
            if(mpp.find(temp) == mpp.end()){
                mpp[temp] = i;
                temp = temp->next;
            }
            else return true;
            i++;
        }

        return false;
    }
};
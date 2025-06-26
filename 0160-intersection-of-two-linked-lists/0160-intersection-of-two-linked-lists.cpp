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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp_1 = headA;
        ListNode* temp_2 = headB;
        map<ListNode*,int> mpp;
        map<ListNode*,int>mpp1;

        while(temp_1 != NULL){
            mpp[temp_1] = temp_1->val;
            temp_1 = temp_1->next;
        }

        while(temp_2 != NULL){
            mpp1[temp_2] = temp_2->val;
            temp_2 = temp_2->next;
        }

        auto it1 = mpp.begin();
        auto it2 = mpp1.begin();

        while(it1 != mpp.end()){
            if(mpp1.find(it1->first) != mpp1.end()) return it1->first;
            it1++;

        }
        return NULL;


    }
};
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
        if(head == NULL) return head;
        if(head->next == NULL) return true;

        ListNode* temp = head;
        vector<int>v;

        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }

        int front = 0;
        int back = v.size() - 1;

        while(front < back){
            if(v[front] != v[back]) return false;
            front++;
            back--;
        }

        return true;

    }
};
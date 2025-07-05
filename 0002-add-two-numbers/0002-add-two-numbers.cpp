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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        vector<int>v;

        while(temp1 != NULL && temp2 != NULL){
            int val1 = temp1->val;
            int val2 = temp2->val;
            int add = val1 + val2 + carry;
            if(add < 10){
                v.push_back(add);
                cout<<"This is the first value "<<add<<"\n";
                carry = 0;
            }
            else{
                carry = 1;
                int val = add % 10;
                cout<<"This is the second value "<<val<<"\n";
                v.push_back(val);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
            while(temp1 != NULL){
                int add = temp1->val + carry;
                if(add < 10){
                    v.push_back(add);
                    
                    carry = 0;
                }
                else{
                    carry = 1;
                    int val = add % 10;
                    v.push_back(val);

                }

                temp1 = temp1->next;
            }
            while(temp2 != NULL){
                int add = temp2->val + carry;
                if(add < 10){
                    v.push_back(add);
                    carry = 0;
                }
                else{
                    carry = 1;
                    int val = add % 10;
                    v.push_back(val);

                }

                temp2 = temp2->next;
            }

            if(carry == 1){
                v.push_back(carry);
                carry = 0;
            }

        
        ListNode* head = new ListNode(v[0]);
        ListNode* current = head;
        for(int i = 1; i  < v.size(); i++){
            current->next = new ListNode(v[i]);
            current = current->next;
        }

        return head;
    }
};
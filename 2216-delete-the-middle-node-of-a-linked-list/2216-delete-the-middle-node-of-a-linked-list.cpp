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
    ListNode* deleteMiddle(ListNode* head) {
        int len = sz(head);
        ListNode* temp = head;
        int n = (len / 2) + 1;
        cout<<n<<"\n";
        if(head == NULL || head->next == NULL) return NULL;

        int count = 0;
        count++;
        ListNode* prev = head;
        while(temp != NULL){
            if(count != n){
                prev = temp;
                temp = temp->next;
                count++;
            }
            else{
                cout<<"The value to be removed is " << temp->val<<"\n";
                temp = temp->next;
                prev->next = temp;
                break;
            }
        }

        return head;
    }

    int sz(ListNode* head){
        int count = 0;
        if(head == NULL || head->next == NULL) return 0;

        ListNode* temp = head;
        count++;

        while(temp->next != NULL){
            temp = temp->next;
            count++;
        }

        return count;
    }
};
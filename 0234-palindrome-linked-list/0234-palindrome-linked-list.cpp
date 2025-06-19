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
        struct ListNode* ptr = head;
        struct ListNode* r_head = NULL;

        if(head == NULL || head->next==NULL) return (head);
        while(ptr){
            struct ListNode* temp = new ListNode(ptr->val);
            temp->next = r_head;
            r_head = temp;
            ptr = ptr->next;
        }
        struct ListNode* temp1 = r_head;
        if(!r_head) cout<<"no"<<endl;
        while(temp1){
            cout<<temp1->val<<endl;
            temp1 = temp1->next;
        }
        while(head && r_head){
            if( head->val != r_head->val) return false;

            head = head->next;
            r_head = r_head->next;
        }
        return true;
    }
};
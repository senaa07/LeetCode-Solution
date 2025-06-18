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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if( head == NULL) return head;

        int ptr=k, ptr1=k, c=0;
        struct ListNode* current = head;
        struct ListNode* prev = NULL;
        struct ListNode* next = NULL;

        while(ptr-- && current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next; 
        }

        if(current){
            struct ListNode* temp = current;
            while(ptr1-- && temp){
                c++;
                temp = temp->next;
            }

            if(c==k){
                head->next = reverseKGroup(current,k);
            }else{
                head->next = current;
            }
        }
        return prev;
    }
};
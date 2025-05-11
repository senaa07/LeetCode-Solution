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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode* last= head;
        struct ListNode* first= head;
        int m=0;

        while(last != NULL){
            last = last->next;
            m++;
        }
        if(m==1) return NULL;
        if(m==n){
            return first = first->next;
            
        }
        if (n==1){
            while(m!=2){
                first= first->next;
                m--;
            }
            first->next = NULL;
            return head;
        }
        last = head->next->next;
        
        for(int i=0;i<m-n-1;i++){
            last = last->next;
            first = first->next;
        }
        first->next = last;
        return head;
    }
};
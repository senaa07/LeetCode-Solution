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
        int n=0;
        ListNode *temp1 = head;
        ListNode *temp2 = head;

        while(temp1 != NULL){
            n++;
            temp1 = temp1->next;
        }
        temp1 = NULL;

        if( n == 1 ) return temp1;
        
        n = n/2;

        while( n >=0 ){
            if( n == 0 ){
                temp1->next = temp2->next;
                break;
            }
            n--;
            temp1 = temp2;
            temp2 = temp2->next;
        }

        return head;
    }
};
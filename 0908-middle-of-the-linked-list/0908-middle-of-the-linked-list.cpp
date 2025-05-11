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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp1 = head;
        int m=0;
        while(temp1 != NULL){
            temp1= temp1->next;
            m++;
        }
        temp1 = head;
        m = m/2;
        while(m != 0){
            temp1 = temp1->next;
            m--;
        }
        return temp1;
    }
};
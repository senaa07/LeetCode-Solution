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
    void deleteNode(ListNode* node) {
        ListNode *current = node;
        ListNode *nextNode = current->next;
        

        while(nextNode->next != NULL){
            current->val = nextNode->val;

            current = current->next;
            nextNode = nextNode->next;
        }
        current->val = nextNode->val;
        current->next = NULL;
        
        return;
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL) return head;
        ListNode *root = head;
        int length = 0;
        while(root != NULL){
            root = root->next;
            length++;
        }
        k = k%length;
        root= head;
        ListNode *prev = NULL;
        
        while(k>0){
            prev = root;
            root = root->next;

            if(root->next == NULL){
                prev->next = NULL;
                root->next = head;
                head = root;
                k--;
            }
        }
        return head;
    }
};
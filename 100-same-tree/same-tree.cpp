/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    bool result = true;
    void checkSame(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return;
        if(!node1 || !node2){
            result=false;
            return;
        }
        
        checkSame(node1->left, node2->left);
        if(node1->val != node2->val) result=false;
        checkSame(node1->right, node2->right);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        checkSame(p,q);
        return result;

    }
};
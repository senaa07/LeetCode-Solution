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
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;

    void inorder(TreeNode* node){
        if(!node) return;
        
        inorder(node->left);

        if(prev && prev->val > node->val){
            if(!first) first = prev;
            second = node;
        }
        prev= node;
        inorder(node->right);
        return;
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(second->val,first->val);
        return;
    }
};
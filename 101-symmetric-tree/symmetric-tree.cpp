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
    bool isMirror = true;
    void checkMirror(TreeNode* node1, TreeNode*node2){
        if(!node1 && !node2) return;
        if(!node1 || !node2) {
            isMirror=false;
            return ;
        }
        checkMirror(node1->left,node2->right);
        if(node1->val != node2->val) isMirror=false;
        checkMirror(node1->right,node2->left);

    }

public:
    bool isSymmetric(TreeNode* root) {
        checkMirror(root->left,root->right);
        return isMirror;
    }
};
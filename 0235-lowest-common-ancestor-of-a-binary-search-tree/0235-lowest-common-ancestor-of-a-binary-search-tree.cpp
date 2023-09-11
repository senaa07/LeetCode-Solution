/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* solve( TreeNode* root,TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if( root == p || root == q){
            if(root == p) return p;
            if(root == q) return q;
        }

        TreeNode* left = solve(root->left,p,q);
        TreeNode* right = solve(root->right,p,q);
        if( left && right){
            return root;
        }
        if( !left || !right ){
            if(!left) return right;
            return left;
        }
        return NULL;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //int val1 = p->val;
        //int val2 = q->val;
        //bool a = 
        if(!root) return NULL;
        if( root == p || root == q){
            if(root == p) return p;
            if(root == q) return q;
        }

        TreeNode* left = solve(root->left,p,q);
        TreeNode* right = solve(root->right,p,q);
        if( left && right){
            return root;
        }
        if( !left || !right ){
            if(!left) return right;
            return left;
        }
        return NULL;
        //return solve(root,p,q);
    }
};
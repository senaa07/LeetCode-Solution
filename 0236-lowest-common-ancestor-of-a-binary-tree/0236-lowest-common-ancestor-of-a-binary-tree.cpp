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
/*
    TreeNode* lcs(TreeNode*root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        
        if(root == p || root == q){
            if(root==p) return p;
            if(root==q) return q;
        }
        if(root->left !=NULL){
            TreeNode* a = lcs(root->left,p,q);
            TreeNode* b = lcs(root->right,p,q);

            if(a && b){
                return root;
            }
            else{
                if(a != NULL ) return a;
                if(b !=NULL ) return b;
            }
        }
        return NULL;
    }
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //TreeNode* ans = lcs(root,p,q);
        //return ans;

        //if(!root) return NULL;
        
        if(root==NULL || root==p || root==q){
            return root;
        }   
        
        TreeNode* a = lowestCommonAncestor(root->left,p,q);
        TreeNode* b = lowestCommonAncestor(root->right,p,q);

        if(a && b){
            return root;
        }
        else{
            if(a != NULL ) return a;
            if(b !=NULL ) return b;
        }
    
        return NULL;
    }
};
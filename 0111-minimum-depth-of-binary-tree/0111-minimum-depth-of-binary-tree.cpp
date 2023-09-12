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
public:
    int ans;
    int solve(TreeNode* root, int level){
        if(!root) return INT_MAX;
        if(!root->left &&!root->right) return level;
        
        int num1 = solve(root->left,level+1);
        int num2 = solve(root->right,level+1);

        return min(num1,num2);
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return solve(root,1);
    }
};
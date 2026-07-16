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
    pair<int,int> solve(TreeNode* node,int level){
        if(!node) return {-2,level+1};

        pair<int,int> left = solve(node->left,level+1);
        pair<int,int> right = solve(node->right,level+1);

        if(left.first == -2 && right.first==-2) return {node->val,level+1};
        if(left.first ==-2 ) return right;
        if(right.first ==-2 ) return left;

        if(left.second < right.second) return right;
        return left;
    }


public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        if(!(root->left) && !(root->right) ) return root->val;
        pair<int,int> ans = solve(root,0);
        return ans.first;
    }
};
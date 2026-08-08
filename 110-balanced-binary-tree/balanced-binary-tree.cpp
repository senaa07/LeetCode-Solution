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
    bool ans = true;
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        helper(root);
        return ans;
    }

    int helper(TreeNode* root){
        if(!root) return 0;
        if(!ans) return 0;
        int leftHeight = helper(root->left);
        int rightHeight = helper(root->right);

        if(abs(leftHeight - rightHeight)>1) ans = false;

        return max(leftHeight,rightHeight) + 1;
    }
};
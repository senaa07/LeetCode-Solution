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
    int ans = INT_MIN;
    int PathFinder(TreeNode* node){
        if(!node) return 0;
        int sum;
        int leftMaxPath = max(0,PathFinder(node->left));
        int rightMaxPath = max(0,PathFinder(node->right));



        sum = max(leftMaxPath+node->val, max(rightMaxPath + node->val, node->val));

        ans = max(leftMaxPath + rightMaxPath + node->val, max(ans, sum));

        return sum;
    }

public:
    int maxPathSum(TreeNode* root) {
        if(!root->left & !root->right) return root->val;

        PathFinder(root);
        return ans;
    }
};
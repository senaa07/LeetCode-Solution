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
    int PathFinder(TreeNode* root){
        if(!root) return 0;
        int sum;
        int leftMaxPath = PathFinder(root->left);
        int rightMaxPath = PathFinder(root->right);



        sum = max(leftMaxPath+root->val, max(rightMaxPath + root->val, root->val));

        ans = max(leftMaxPath + rightMaxPath + root->val, max(ans, sum));

        return sum;
    }

public:
    int maxPathSum(TreeNode* root) {
        if(!root->left & !root->right) return root->val;

        PathFinder(root);
        return ans;
    }
};
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
    vector<vector<int>> ans;
public:

    void solve(TreeNode* root,int rem, vector<int> &temp ){
        if(!root) return;
        if(!root->left && !root->right){
            temp.push_back(root->val);
            if(rem == root->val) ans.push_back(temp);
            temp.pop_back();
            return;
        }

        temp.push_back(root->val);
        solve(root->left,rem - root->val, temp);
        solve(root->right,rem - root->val, temp);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        if(!root) return ans;
        solve(root, targetSum, temp);
        return ans;
    }
};
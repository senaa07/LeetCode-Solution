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
    vector<vector<int>> ans;
    void checkPath(TreeNode* node,int targetSum, long long int sum, vector<int> path){
        if(!node) return; //whennode is null
        

        path.push_back(node->val);
        sum += node->val;
        if(node->left == NULL && node->right == NULL && ( sum == targetSum )){
            ans.push_back(path);
            return;
        }

        checkPath(node->left, targetSum,sum,path);
        checkPath(node->right,targetSum,sum,path);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currentPath;
        long long int currentSum=0;
        checkPath(root,targetSum, currentSum, currentPath);
        return ans;
    }
    
};
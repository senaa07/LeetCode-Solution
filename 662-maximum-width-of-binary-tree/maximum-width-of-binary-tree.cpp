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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        int size=0;
        long long ans= 0;
        q.push({root,0});
        long long normal= 0;
        while(!q.empty()){
            size = q.size();
            normal = q.front().second;
            ans = max(ans, q.back().second - q.front().second + 1);
            
            while(size--){
                auto [node,index] = q.front();
                q.pop();

                if(node->left) q.push({node->left, 2 * (index-normal)+1 });
                
                if(node->right) q.push({node->right, 2 * (index-normal) + 2 });
            }            
        }

        return ans;
    }
};
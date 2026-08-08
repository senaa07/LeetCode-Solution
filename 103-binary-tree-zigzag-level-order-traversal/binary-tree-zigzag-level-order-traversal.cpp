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
    vector<vector<int>> res;
    void DFS(TreeNode* node, int level){
        if(!node) return;

        if(level == res.size()){
            res.push_back({});
        }
        res[level].push_back(node->val);

        DFS(node->left, level+1);
        DFS(node->right, level+1);

        

        return;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        DFS(root,0);

        for(int i=0;i<res.size();i++){
            if(i%2){
                reverse(res[i].begin(), res[i].end());
            }
        }

        return res;
    }
};
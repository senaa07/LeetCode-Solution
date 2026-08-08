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
    map<int,vector<pair<int,int>>> columnNodes;

    void dfs(TreeNode* node, int row, int col){
        if(!node) return;

        columnNodes[col].push_back({row,node->val});

        dfs(node->left, row+1, col-1);
        dfs(node->right, row+1, col+1);

        return;
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return{};
        dfs(root, 0, 0);
        vector<vector<int>> ans;

        for(auto [columns,rows]: columnNodes){
            vector<int> nodes;
            sort(rows.begin(), rows.end());

            for(auto node: rows){
                nodes.push_back(node.second);
            }

            ans.push_back(nodes);
        }
        return ans;
        
    }
};
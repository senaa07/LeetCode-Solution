/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:
    int targetIndex = -1;
    unordered_map<int, vector<int>> adj;
    
    void buildGraph(TreeNode* node, TreeNode* parent){
        if(!node) return;

        if(parent){
            adj[node->val].push_back(parent->val);
            adj[parent->val].push_back(node->val);
        }
        buildGraph(node->left, node);
        buildGraph(node->right, node);
        return;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        buildGraph(root, NULL);

        unordered_set<int> visited;
        queue<int> q;

        q.push(target->val);
        visited.insert(target->val);

        int dist = 0;

        while(!q.empty()){

            if(dist == k){
                vector<int> res;

                while(!q.empty()){
                    res.push_back(q.front());
                    q.pop();
                }

                return res;
            }

            int length = q.size();

            while(length--){
                auto node = q.front();
                q.pop();
                for(auto& neighbour:adj[node]){
                    if(!visited.count(neighbour)){
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
            dist++;
        }
        return {};     
    }
};
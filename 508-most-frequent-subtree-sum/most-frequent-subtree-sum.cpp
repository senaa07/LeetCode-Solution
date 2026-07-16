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
    int maxFreq=0;
    unordered_map<int,int> freq;

    int calculateSumAtEachNode(TreeNode* node){
        if(!node) return 0;

        int sum = node->val + calculateSumAtEachNode(node->left) + calculateSumAtEachNode(node->right);

        freq[sum]++;
        if(freq[sum] > maxFreq) maxFreq = freq[sum];
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        calculateSumAtEachNode(root);
        for(auto it: freq){
            if(it.second == maxFreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
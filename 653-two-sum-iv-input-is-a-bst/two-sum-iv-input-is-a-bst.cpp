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
    vector<int> nodeVal;
    void inorder(TreeNode* node){
        if(!node) return;
        
        inorder(node->left);
        nodeVal.push_back(node->val);
        inorder(node->right);
        return;

    }
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int left=0;int right=nodeVal.size()-1;
        if(nodeVal.size()==1) return false;
        while(left < right){
            int x = nodeVal[right];
            if(x + nodeVal[left] == k ) return true;
            if(x + nodeVal[left] < k ){
                left++;
            }else{
                right--;
            }
        }
        return false;
    }
};
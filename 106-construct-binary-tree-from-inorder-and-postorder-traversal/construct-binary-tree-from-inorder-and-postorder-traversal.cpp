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
    unordered_map<int,int> inorderIndex;

    TreeNode* helper(vector<int> postorder, int postEnd, int inStart,int inEnd){
        if(inStart>inEnd)return nullptr;

        int rootVal = postorder[postEnd];

        TreeNode* root= new TreeNode(rootVal);

        int mid = inorderIndex[rootVal];
        int sizeRight = inEnd - mid;

        root->right = helper(postorder, postEnd-1, mid+1, inEnd);
        root->left = helper(postorder, postEnd-sizeRight-1, inStart,mid-1);

        return root;
    }


public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            inorderIndex[inorder[i]] = i;
        }

        return helper(postorder, postorder.size()-1,0,inorder.size()-1);
    }
};
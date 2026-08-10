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
    unordered_map<int,int> inorderMap;

    TreeNode* builtNodeInTree(vector<int> preorder, int preStart, int inStart, int inEnd){
        if(inStart> inEnd ) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal];
        int leftSize = mid - inStart;

        root->left = builtNodeInTree(preorder, preStart+1, inStart, mid-1);
        root->right = builtNodeInTree(preorder, preStart+leftSize+1, mid+1, inEnd);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0 ; i< inorder.size() ; i++){
            inorderMap[inorder[i]] =i;
        }

        return builtNodeInTree(preorder, 0, 0, inorder.size()-1);
    }
};
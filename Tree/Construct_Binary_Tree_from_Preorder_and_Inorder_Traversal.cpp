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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeNode(preorder, inorder, 0, 0, inorder.size()-1);
        
    }
private: 
     TreeNode* buildTreeNode(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd){
        if(inStart > inEnd) return NULL;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int rootIdx = -1;
        for(int i = inStart; i <= inEnd; i++){
            if(inorder[i] == rootVal){
                rootIdx = i;
                break;
            }
        }
        root->left = buildTreeNode(preorder, inorder, preStart + 1, inStart, rootIdx - 1);
        root->right = buildTreeNode(preorder, inorder, preStart + 1 + rootIdx - inStart, rootIdx + 1, inEnd);
        
        return root;
     }

};

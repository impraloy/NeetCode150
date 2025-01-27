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
        int dfs(TreeNode* root){
            if(!root) return 0;
            int leftNode = dfs(root->left);
            int rightNode = dfs(root->right);
            int balancedFactor = abs(leftNode - rightNode);
            if(balancedFactor > 1 || leftNode == -1 || rightNode == -1){
                return -1;
            }
            return 1 + max(leftNode, rightNode);
        
    }
public:
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return dfs(root) == -1 ? false : true;

        
    }
};

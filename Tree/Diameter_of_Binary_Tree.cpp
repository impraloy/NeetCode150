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
    int findMaxD(TreeNode* root, int& result){
        if(!root) return 0;

        int left = findMaxD(root->left, result);
        int right = findMaxD(root->right, result);
        result = max(result, left + right);

        return 1 + max(left, right);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result =  0;
        findMaxD(root, result);
        return result;
        
    }
};

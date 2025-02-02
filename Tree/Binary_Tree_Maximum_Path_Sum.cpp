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
    int getMaxPathSum(TreeNode* root, int& maxPathSum){
        if(!root) return 0;

        int maxLeft = max(getMaxPathSum(root->left, maxPathSum), 0);
        int maxRight = max(getMaxPathSum(root->right, maxPathSum), 0);
        maxPathSum = max(maxPathSum, root->val + maxLeft + maxRight);
        return root->val + max(maxLeft, maxRight);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        getMaxPathSum(root, maxPathSum);
        return maxPathSum;

    }
};

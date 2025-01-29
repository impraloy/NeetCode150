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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> results;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            TreeNode* rightSide = nullptr;
            int length = que.size();

            for(int i = 0; i<length; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node){
                    rightSide = node;
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            if(rightSide){
                results.push_back(rightSide->val);
            }
        }
        return results;
        
    }
};

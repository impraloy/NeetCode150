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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;

        if(!root) return results;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            vector<int> level;
            for(int i = que.size(); i>0; i--){
                TreeNode* node = que.front();
                que.pop();
                if(node){
                    level.push_back(node->val);
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            if(!level.empty()){
                results.push_back(level);
            }    
        }
        return results;  
    }
};

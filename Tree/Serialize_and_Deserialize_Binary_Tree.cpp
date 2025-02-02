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

class Codec {
private:
    void serializeDfs(TreeNode* node, string& s){
        if(!node){
            s.append(",N");
            return;
        }else{
            s.append(",");
            s.append(to_string(node->val));
        }
        serializeDfs(node->left, s);
        serializeDfs(node->right, s);
    }
    TreeNode* deserializeDfs(string& data, int& i){
        i++;
        string num;
        while (i < data.size() && data[i] != ',') {
            num += data[i];
            i++;
        }

        if (num == "N") { return nullptr; }
        TreeNode *node = new TreeNode(stoi(num));

        node->left = deserializeDfs(data, i);
        node->right = deserializeDfs(data, i);

        return node;

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeDfs(root, s);
        return s; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        TreeNode* root = deserializeDfs(data, i);
        return root;  
    }
};

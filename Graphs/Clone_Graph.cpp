/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* deepCopyGraph(Node* node, unordered_map<Node*, Node*> &map){
        if(map.count(node)) return map[node];

        map[node] = new Node(node->val);
        for(auto neighbor: node->neighbors){
            map[node]->neighbors.push_back(deepCopyGraph(neighbor, map));
        }
        return map[node];
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> map;
        return deepCopyGraph(node, map);

        
    }
};

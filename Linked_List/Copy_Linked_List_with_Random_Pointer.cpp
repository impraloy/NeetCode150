/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //creating a map to store original and copy list
        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        
        //copy the value to the map
        while(curr != nullptr){
            Node* copy = new Node(curr->val);
            mp[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        
        while(curr != nullptr){
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
        
    }
};

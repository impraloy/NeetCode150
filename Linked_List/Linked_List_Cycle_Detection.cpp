/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//This solution used Floyd's Cycle Finding algorithm which also known as Fast and slow pointer approach.
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) return true;
        }
        return false;
        
    }
};

/* Alternative Solution using HashSet
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        ListNode* curr = head;

        while(curr){
            if(seen.find(curr) != seen.end()) return true;
        
        seen.insert(curr);
        curr = curr->next;
       }
       return false; 
    }
};
*/
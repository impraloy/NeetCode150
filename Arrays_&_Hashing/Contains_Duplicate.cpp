class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hash_set;
        for(int i : nums){
            if(hash_set.count(i)) return true;
           
         hash_set.insert(i);
        }
        return false;
    }

};

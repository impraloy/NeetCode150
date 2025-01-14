class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;

        for(const int &num : nums){
            set.insert(num);
        }

        int longestStreak = 0;
        for(const int &start : set){
            if(set.find(start-1) == set.end()){
                int end = start + 1;
                while(set.find(end) != set.end()){
                    end++;
                }
                longestStreak = max(longestStreak, end-start);

            }

        }
        return longestStreak;
    }
};

//Alternative Solution

/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int results = 0;

        for (int num : nums) {
            if (!map[num]) {
                map[num] = map[num - 1] + map[num + 1] + 1;
                map[num - map[num - 1]] = map[num];
                map[num + map[num + 1]] = map[num];
                results = max(results, map[num]);
            }
        }
        return results;
    }
};

*/
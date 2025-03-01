class Solution {
    unordered_map<int, vector<int>> map;
    unordered_set<int> visited;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        for(int i = 0; i < numCourses; i++){
            map[i] = {};
        }

        for(const auto& prereq : prerequisites){
            map[prereq[0]].push_back(prereq[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)) return false;
        }
        return true;   
    }
private:
    bool dfs(int numOfCourses){
        if(visited.count(numOfCourses)) return false;

        if(map[numOfCourses].empty()) return true;

        visited.insert(numOfCourses);

        for(int pre : map[numOfCourses]){
            if(!dfs(pre)) return false;
        }
        
        visited.erase(numOfCourses);
        map[numOfCourses].clear();
        return true;
    }
};

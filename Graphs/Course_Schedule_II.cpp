class Solution {
    unordered_map<int, vector<int>> map;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto &pre : prerequisites){
            map[pre[0]].push_back(pre[1]);
        }

        vector<int> result;
        unordered_set<int> visited;
        unordered_set<int> cycleDetected;

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i, map, visited, cycleDetected, result)){
                return {};
            }
        }
        return result;
    }
private:
    bool dfs(int course, unordered_map<int, vector<int>> &map,
             unordered_set<int> &visited, unordered_set<int> &cycleDetected, 
             vector<int> &result){
                if(cycleDetected.count(course)) return false;

                if(visited.count(course)) return true;

                cycleDetected.insert(course);

                if(map.count(course)){
                    for(int p : map.at(course)){
                        if(!dfs(p, map, visited, cycleDetected, result)){
                            return false;
                        }
                    }
                }
                cycleDetected.erase(course);
                visited.insert(course);
                result.push_back(course);
                return true;
             }
};

class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> store; 
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        pair<string, int> newPair = {value, timestamp};
        store[key].push_back(newPair);   
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> &vals = store[key];
        int low = 0, high = vals.size()-1;
        string results;

        while(low <= high){
            int mid = low + (high - low) /2;
            if(vals[mid].second == timestamp) {return vals[mid].first;}

            if(vals[mid].second <= timestamp){
                low = mid + 1;
                results = vals[mid].first;
            }else{
                high = mid - 1;
            }
        }
        return results;
        
    }
};

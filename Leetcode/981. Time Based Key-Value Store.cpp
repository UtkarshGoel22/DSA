class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});    
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";
        int low = 0, high = store[key].size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (store[key][mid].first == timestamp) return store[key][mid].second;
            else if (store[key][mid].first < timestamp) low = mid+1;
            else high = mid-1;
        }
        return (high >= 0) ? store[key][high].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> keyVals;
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        keyVals[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& arr = keyVals[key];
        int l = 0, r = arr.size() - 1;
        string res = "";
        while (l <= r) {
            int mid = (l + r) / 2;

            if (arr[mid].second <= timestamp) {
                res = arr[mid].first;
                l = mid + 1;
            } else r = mid - 1;
        }
        return res;
    }
};

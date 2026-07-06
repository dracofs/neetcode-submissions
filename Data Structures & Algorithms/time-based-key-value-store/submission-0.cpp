class TimeMap {
public:
    // map of timestamps for a certain key string
    unordered_map<string, vector<int>> key_times;
    // map of timestamp
    unordered_map<string, vector<string>> key_val;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        key_val[key].push_back(value);
        key_times[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        // binsearch for occurence of key <= aforementioned timestamp, then keep increasing while key is there and timestamp fits
        vector<int> times = key_times[key];
        int lo = 0;
        int hi = times.size() - 1;
        int mid;
        string res = "";

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            
            if (times[mid] <= timestamp) {
                lo = mid + 1;
                res = key_val[key][mid];
            } else hi = mid - 1;
        }

        return res;
    }
};

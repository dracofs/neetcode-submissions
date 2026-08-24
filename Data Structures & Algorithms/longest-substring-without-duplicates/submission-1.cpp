class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0;
        std::unordered_map<char, int> loc;
        for (int right{ left }; right < s.size(); right++) {
            auto exists = loc.find(s[right]);

            if (exists != loc.end()) {
                if (exists->second >= left) left = exists->second + 1;
                exists->second = right;
            } else {
                loc[s[right]] = right;
            }

            res = max(right - left + 1, res);
        }

        return res;
    }
};

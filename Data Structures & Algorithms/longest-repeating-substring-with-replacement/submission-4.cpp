class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> f(26);
        int l = 0, r = 0, maxf = 0;
        int res = 0;
        while (r < s.size()) {
            f[s[r] - 'A']++;
            maxf = max(maxf, f[s[r] - 'A']);

            while (r - l + 1 - maxf > k) {
                f[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};

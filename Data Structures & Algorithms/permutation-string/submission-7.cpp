class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        int k = s1.size();
        vector<int> f1(26);
        vector<int> f2(26);

        for (char c : s1) { f1[c - 'a']++; }
        for (int i = 0; i < k; i++) { f2[s2[i] - 'a']++; }
        int matches = 0;

        // count matches
        for (int i = 0; i < 26; i++) {
            if (f2[i] >= f1[i]) matches++;
        }

        int l = 0, r = k - 1;
        do {
            
            // cout << "[DEBUG] Matching string: " << s1 << ", against: " << s2.substr(l, r - l + 1) << " at " << matches << " matches." << endl;

            // check match
            if (matches == 26) return true;

            if (r == s2.size() - 1) break;
            // advance ptrs & update freqs


            if (f1[s2[l] - 'a'] == f2[s2[l] - 'a']) {
                matches--;
                // cout << "[DEBUG] Char: " << s2[l] << " is being removed, decreasing number of matches by 1." << endl;
            }
            f2[s2[l++] - 'a']--;
            if (f1[s2[r + 1] - 'a'] == f2[s2[r + 1] - 'a'] + 1) {
                matches++;
                // cout << "[DEBUG] Char: " << s2[r + 1] << " is being added, increasing number of matches by 1." << endl;
             
            }
            f2[s2[++r] - 'a']++;


        } while (true);

        return false;
    }
};

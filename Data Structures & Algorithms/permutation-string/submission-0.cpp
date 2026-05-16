class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // O(s1.size()) * O(s2.size() - s1.size());
        if (s1.size() > s2.size()) return false;

        vector<int> s1freq(26);
        vector<int> s2freq(26);

        // compute initial freq count
        for (int i = 0; i < s1.size(); i++) {
            s1freq[s1[i] - 'a']++;
            s2freq[s2[i] - 'a']++;
        } 
        
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (s1freq[i] == s2freq[i]) count++;
        }

        if (count == 26) return true;

        int left = 0, right = s1.size() - 1;

        while (right < s2.size()) {
            if (count == 26) return true;
            s2freq[s2[left] - 'a']--;

            if (s1freq[s2[left] - 'a'] == s2freq[s2[left] - 'a']) count++;
            else if (s1freq[s2[left] - 'a'] == s2freq[s2[left] - 'a'] + 1) count--;

            left++, right++;
            if (right >= s2.size()) break;

            s2freq[s2[right] - 'a']++;

            if (s1freq[s2[right] - 'a'] == s2freq[s2[right] - 'a']) count++;
            else if (s1freq[s2[right] - 'a'] == s2freq[s2[right] - 'a'] - 1) count--;
        }

        return false;
    }
};

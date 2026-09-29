class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> f(26, 0);
        for (char c : tasks) {
            f[c - 'A']++;
        }

        int maxf = *max_element(f.begin(), f.end());
        int maxc = 0;
        for (int fr : f) {
            if (fr == maxf) {
                maxc++;
            }
        }
        
        int time = (maxf - 1) * (n + 1) + maxc;
        return max((int)tasks.size(), time);
    }
};

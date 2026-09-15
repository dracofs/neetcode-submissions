class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indeg(n);
        vector<vector<int>> nei(n);

        for (auto& prereq : prerequisites) {
            indeg[prereq[0]]++;
            nei[prereq[1]].push_back(prereq[0]);
        }

        queue<int> q;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                count++;
            }
        }

        while (!q.empty()) {
            int top = q.front(); q.pop();
            for (auto& ne : nei[top]) {
                if (--indeg[ne] == 0) {
                    q.push(ne);
                    count++;
                }
            }
        }

        return count == n;
    }
};

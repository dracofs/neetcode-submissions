class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indeg(n);
        vector<vector<int>> outdeg(n);

        for (auto& prereq : prerequisites) {
            indeg[prereq[0]]++;
            outdeg[prereq[1]].push_back(prereq[0]);
        }

        queue<int> q;
        vector<int> res;
        vector<bool> visited(n);
        for (int i{0}; i < n; i++) {
            if (indeg[i] == 0) {
                visited[i] = true;
                res.push_back(i);
                q.push(i);
            }
        }

        while (!q.empty()) {
            int top = q.front(); q.pop();
            for (int neighb : outdeg[top]) {
                indeg[neighb]--;
                if (indeg[neighb] == 0 && !visited[neighb]) {
                    visited[neighb] = true;
                    q.push(neighb);
                    res.push_back(neighb);
                }
            }
        }
        if (res.size() != n) return {};
        else return res;
    }
};

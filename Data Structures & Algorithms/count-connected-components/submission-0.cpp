class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n);
        queue<pair<int, int>> q;

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                res++;
                bfs(i, -1, adj, visited);
            }
        }
        return res;
    }

    void bfs(int source, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q;
        q.push({source, parent});
        visited[source] = true;

        while (!q.empty()) {
            int source = q.front().first, parent = q.front().second; q.pop();
            for (auto& neighbor : adj[source]) {
                if (neighbor == parent) continue;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, source});
                }
            }
        }

    }
};

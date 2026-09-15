class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // any acyclic graph is a tree, validTree is equivalent to checking the graph for a cycle
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n);
        queue<pair<int, int>> q;
        visited[0] = true;
        q.push({0, -1});
        int traversed = 1;
        while (!q.empty()) {
            pair<int, int> top = q.front(); q.pop();
            int source = top.first, parent = top.second;
            for (auto& n : adj[source]) {
                if (n == parent) continue;
                if (visited[n]) return false;
                q.push({n, source});
                visited[n] = true;
                traversed++;
            }
        }

        return traversed == n;
    }
};

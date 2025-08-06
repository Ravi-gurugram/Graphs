class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n); // pair<neighbor, direction>

        // Build bidirectional graph with direction flag
        for (auto& conn : connections) {
            int from = conn[0], to = conn[1];
            graph[from].push_back({to, 1});  // 1 means original direction (from → to)
            graph[to].push_back({from, 0});  // 0 means reverse direction (to ← from)
        }

        vector<bool> visited(n, false);
        int count = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (auto& [nei, dir] : graph[node]) {
                if (!visited[nei]) {
                    count += dir; // if edge is in wrong direction (away from 0), we need to reverse
                    dfs(nei);
                }
            }
        };

        dfs(0); // Start DFS from city 0

        return count;
    }
};


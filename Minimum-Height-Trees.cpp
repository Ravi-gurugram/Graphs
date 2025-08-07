class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // only one node
        
        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0); // to count degree of each node

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Step 2: Initialize queue with all leaves (nodes with degree 1)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1)
                q.push(i);
        }

        // Step 3: BFS from leaves inward
        vector<int> res;
        while (!q.empty()) {
            int size = q.size();
            res.clear(); // last level of nodes are the potential roots
            for (int i = 0; i < size; ++i) {
                int node = q.front(); q.pop();
                res.push_back(node);

                for (int neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }

        return res;
    }
};

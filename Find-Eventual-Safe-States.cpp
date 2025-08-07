class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revAdj(n);
        vector<int> indegree(n, 0);

        // Step 1: Reverse the graph
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                revAdj[v].push_back(u);
                indegree[u]++;
            }
        }

        // Step 2: Kahn's Algorithm using queue
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<bool> safe(n, false);
        while (!q.empty()) {
            int node = q.front(); q.pop();
            safe[node] = true;
            for (int neighbor : revAdj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Collect all safe nodes
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (safe[i])
                ans.push_back(i);
        }
        return ans;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeCount = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                int nodeCount = 0;
                int edgeCount = 0;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    nodeCount++;
                    edgeCount += adj[curr].size();

                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                // Each edge is counted twice (once from each node)
                edgeCount /= 2;

                // Check if it's a complete graph
                if (edgeCount == (nodeCount * (nodeCount - 1)) / 2) {
                    completeCount++;
                }
            }
        }

        return completeCount;
    }
};
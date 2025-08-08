class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Step 1: Build graph
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // Step 2: Ancestors tracking
        vector<set<int>> ancestors(n);
        queue<int> q;

        // Step 3: Start with zero indegree nodes
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Step 4: Topological BFS
        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v : adj[u]) {
                // add all ancestors of u to v
                ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());
                ancestors[v].insert(u); // u is also an ancestor of v

                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        // Step 5: Convert sets to sorted vectors
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return res;
    }
};

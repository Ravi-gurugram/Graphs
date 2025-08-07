class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);     // adjacency list
        vector<int> indegree(n, 0);     // indegree for Kahn's algo

        for (auto& edge : richer) {
            int rich = edge[0];
            int lessRich = edge[1];
            adj[rich].push_back(lessRich); // edge from rich -> lessRich
            indegree[lessRich]++;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = i; // initially assume self is the quietest

        queue<int> q;

        // Step 1: Start with people who have no richer people
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Step 2: Topological BFS
        while (!q.empty()) {
            int person = q.front(); q.pop();
            for (int nei : adj[person]) {
                // If the current person's quietest is quieter than neighbor's quietest
                if (quiet[ans[person]] < quiet[ans[nei]])
                    ans[nei] = ans[person];  // propagate the quietest person

                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redAdj(n), blueAdj(n);

        // Build adjacency lists
        for (auto& e : redEdges) redAdj[e[0]].push_back(e[1]);
        for (auto& e : blueEdges) blueAdj[e[0]].push_back(e[1]);

        vector<vector<bool>> visited(n, vector<bool>(2, false)); // visited[node][color]
        vector<int> res(n, -1);
        queue<tuple<int, int, int>> q; // node, steps, last_color

        // Start BFS from node 0 with both red and blue
        q.push({0, 0, 0}); // Red
        q.push({0, 0, 1}); // Blue
        visited[0][0] = visited[0][1] = true;
        res[0] = 0;

        while (!q.empty()) {
            auto [node, dist, last_color] = q.front(); q.pop();

            // Decide next color
            vector<vector<int>>& nextAdj = (last_color == 0) ? blueAdj : redAdj;
            int next_color = 1 - last_color;

            for (int nei : nextAdj[node]) {
                if (!visited[nei][next_color]) {
                    visited[nei][next_color] = true;
                    q.push({nei, dist + 1, next_color});
                    if (res[nei] == -1) res[nei] = dist + 1;
                }
            }
        }

        return res;
    }
};

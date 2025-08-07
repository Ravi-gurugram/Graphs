class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        for (auto& path : paths) {
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }

        vector<int> res(n + 1, 0);  // 1-based garden IDs

        for (int i = 1; i <= n; ++i) {
            bool used[5] = {false};  // flowers 1 to 4

            // Mark flowers used by neighbors
            for (int nei : adj[i]) {
                used[res[nei]] = true;
            }

            // Assign the smallest unused flower
            for (int f = 1; f <= 4; ++f) {
                if (!used[f]) {
                    res[i] = f;
                    break;
                }
            }
        }

        res.erase(res.begin()); // remove dummy 0th index
        return res;
    }
};

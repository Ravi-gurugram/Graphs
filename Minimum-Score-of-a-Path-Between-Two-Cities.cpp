class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1); // node -> [(neighbour, distance)]
        
        for(auto &road : roads){
            int u = road[0], v = road[1], d = road[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> visited(n+1, false);
        int result = INT_MAX;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;

            for(auto &[nei, dist] : adj[node]){
                result = min(result, dist);
                if(!visited[nei]) dfs(nei);
            }
        };

        dfs(1);
        return result;
    }
};

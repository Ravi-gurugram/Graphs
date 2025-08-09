class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});  // from -> {to, cost}
        }

        // Min-heap: (totalCost, node, stops)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0}); // cost, node, stops

        // Distance array [n][k+2] => cost to node i using ≤ k+1 flights
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top(); pq.pop();

            // If we reached destination, return cost
            if (node == dst) return cost;

            // If we can still take another flight
            if (stops <= k) {
                for (auto& nei : adj[node]) {
                    int nextNode = nei.first;
                    int price = nei.second;

                    if (cost + price < dist[nextNode][stops + 1]) {
                        dist[nextNode][stops + 1] = cost + price;
                        pq.push({cost + price, nextNode, stops + 1});
                    }
                }
            }
        }

        return -1;  // Not reachable within k stops
    }
};
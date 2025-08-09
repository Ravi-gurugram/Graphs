#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<62);
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &r : roads) {
            int u = r[0], v = r[1], w = r[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<ll> dist(n, INF);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        // min-heap: (distance, node)
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue; // stale entry

            for (auto &edge : adj[u]) {
                int v = edge.first;
                ll w = edge.second;
                ll nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    ways[v] = ways[u];              // inherit ways
                    pq.push({nd, v});
                } else if (nd == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD; // additional shortest paths
                }
            }
        }

        return ways[n-1];
    }
};

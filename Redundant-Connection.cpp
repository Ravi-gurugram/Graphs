class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }

    bool unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return false;  // cycle detected

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initialize DSU
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (auto &edge : edges) {
            if (!unionSet(edge[0], edge[1])) {
                return edge;  // redundant edge found
            }
        }
        return {};
    }
};

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) parent[px] = py;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Union operations for all pairs
        for (auto &p : pairs) {
            unite(p[0], p[1]);
        }

        // Collect indices by root parent
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        // For each group, sort characters and reassign
        string result = s;
        for (auto &g : groups) {
            vector<int> indices = g.second;
            string chars = "";
            for (int idx : indices) chars += s[idx];

            sort(chars.begin(), chars.end());
            sort(indices.begin(), indices.end());

            for (int i = 0; i < indices.size(); i++) {
                result[indices[i]] = chars[i];
            }
        }

        return result;
    }
};

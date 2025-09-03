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

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for (int i = 0; i < 26; i++) parent[i] = i;

        // Step 1: Process all equalities
        for (auto &eq : equations) {
            if (eq[1] == '=') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                unite(a, b);
            }
        }

        // Step 2: Check all inequalities
        for (auto &eq : equations) {
            if (eq[1] == '!') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                if (find(a) == find(b)) return false;
            }
        }

        return true;
    }
};

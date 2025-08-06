class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start, target = "123450";
        for (auto& row : board)
            for (int val : row)
                start += (val + '0');

        vector<vector<int>> neighbors = {
            {1, 3}, {0, 2, 4}, {1, 5},
            {0, 4}, {1, 3, 5}, {2, 4}
        };

        queue<pair<string, int>> q; // {state, moves}
        unordered_set<string> visited;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [state, steps] = q.front(); q.pop();

            if (state == target) return steps;

            int zero = state.find('0');

            for (int nei : neighbors[zero]) {
                string next = state;
                swap(next[zero], next[nei]);

                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};

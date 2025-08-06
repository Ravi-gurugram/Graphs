class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<pair<int, int>> q; // {current value, steps}
        vector<bool> visited(1001, false);

        q.push({start, 0});
        
        while (!q.empty()) {
            auto [val, steps] = q.front(); q.pop();
            
            if (val == goal) return steps;
            if (val < 0 || val > 1000 || visited[val]) continue;

            visited[val] = true;

            for (int x : nums) {
                q.push({val + x, steps + 1});
                q.push({val - x, steps + 1});
                q.push({val ^ x, steps + 1});
            }
        }

        return -1;
    }
};

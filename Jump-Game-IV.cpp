class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Map value to all indices that have that value
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; ++i) {
            graph[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front(); q.pop();
                if (i == n - 1) return steps;

                // Visit i-1
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                // Visit i+1
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                // Visit same-value indices
                for (int j : graph[arr[i]]) {
                    if (!visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }

                // Clear the value to prevent redundant future jumps
                graph[arr[i]].clear();
            }
            steps++;
        }

        return -1; // Should never reach here
    }
};

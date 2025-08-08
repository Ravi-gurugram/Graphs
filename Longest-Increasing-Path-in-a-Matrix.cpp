class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> indeg(m, vector<int>(n, 0));
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        // Compute indegree for each cell (how many smaller neighbors point to it)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto &d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] < matrix[i][j]) {
                        indeg[i][j]++;
                    }
                }
            }
        }

        // Start BFS from all cells with indegree = 0 (smallest)
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (indeg[i][j] == 0) q.push({i, j});

        int length = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (auto &d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]) {
                        if (--indeg[nx][ny] == 0)
                            q.push({nx, ny});
                    }
                }
            }
            length++;
        }
        return length;
    }
};

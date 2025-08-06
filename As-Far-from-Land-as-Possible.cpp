class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Step 1: Push all land cells into queue
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        // If grid has only land or only water
        if(q.empty() || q.size() == n * n) return -1;
        
        // Step 2: Multi-source BFS
        int dist = -1;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!q.empty()){
            int size = q.size();
            dist++; // increase level
            
            for(int i = 0; i < size; ++i){
                auto [x, y] = q.front(); q.pop();
                
                for(auto [dx, dy] : dirs){
                    int nx = x + dx, ny = y + dy;
                    
                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return dist;
    }
};

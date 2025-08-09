#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        
        using T = pair<int, pair<int,int>>; // (effort, (r, c))
        priority_queue<T, vector<T>, greater<T>> pq;
        
        effort[0][0] = 0;
        pq.push({0, {0,0}});
        
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};
        
        while (!pq.empty()) {
            auto [currEffort, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;
            
            if (r == rows-1 && c == cols-1) 
                return currEffort;
            
            if (currEffort > effort[r][c]) continue; // already found better
            
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int stepEffort = abs(heights[r][c] - heights[nr][nc]);
                    int nextEffort = max(currEffort, stepEffort);
                    if (nextEffort < effort[nr][nc]) {
                        effort[nr][nc] = nextEffort;
                        pq.push({nextEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0; // should never reach here
    }
};


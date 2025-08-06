class Solution {
public:

    // Convert 1D cell number to (row, col) in board
    pair<int, int> getCoordinates(int num, int n) {
        int r = (num - 1) / n;
        int c = (num - 1) % n;
        int row = n - 1 - r;
        int col;
        if (r % 2 == 0)
            col = c;
        else
            col = n - 1 - c;
        return make_pair(row, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;  // pair<position, steps>
        
        q.push(make_pair(1, 0));
        visited[1] = true;

        while (!q.empty()) {
            pair<int, int> front = q.front();
            int curr = front.first;
            int moves = front.second;
            q.pop();

            if (curr == n * n)
                return moves;

            for (int dice = 1; dice <= 6; ++dice) {
                int next = curr + dice;
                if (next > n * n)
                    continue;

                pair<int, int> pos = getCoordinates(next, n);
                int row = pos.first;
                int col = pos.second;

                if (board[row][col] != -1)
                    next = board[row][col];

                if (!visited[next]) {
                    visited[next] = true;
                    q.push(make_pair(next, moves + 1));
                }
            }
        }

        return -1;
    }
};
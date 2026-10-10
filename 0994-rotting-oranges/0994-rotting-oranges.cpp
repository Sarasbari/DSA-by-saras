class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int rowdir[] = {1, -1, 0, 0};
        int coldir[] = {0, 0, 1, -1};
        int minutes = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nextrow = row + rowdir[d];
                    int nextcol = col + coldir[d];

                    if (nextrow >= 0 && nextrow < rows && nextcol >= 0 &&
                        nextcol < cols && grid[nextrow][nextcol] == 1) {
                        grid[nextrow][nextcol] = 2;
                        q.push({nextrow, nextcol});
                    }
                }
            }
            if (!q.empty())
                minutes++;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return minutes;
    }
};
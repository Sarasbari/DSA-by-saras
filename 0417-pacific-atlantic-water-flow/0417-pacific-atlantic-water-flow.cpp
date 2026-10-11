class Solution {
public:
    int rows, cols;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r,
             int c) {

        visited[r][c] = true;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                continue;

            if (visited[nr][nc])
                continue;

            // Reverse flow: move to equal or higher cells
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));

        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Pacific: top and left edges
        for (int c = 0; c < cols; c++)
            dfs(heights, pacific, 0, c);

        for (int r = 0; r < rows; r++)
            dfs(heights, pacific, r, 0);

        // Atlantic: bottom and right edges
        for (int c = 0; c < cols; c++)
            dfs(heights, atlantic, rows - 1, c);

        for (int r = 0; r < rows; r++)
            dfs(heights, atlantic, r, cols - 1);

        vector<vector<int>> ans;

        // Find cells reachable from both oceans
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};

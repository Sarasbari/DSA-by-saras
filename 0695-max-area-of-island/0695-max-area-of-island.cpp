class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxarea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j, n, m);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        int area = 1;
        area += dfs(grid, i + 1, j, n, m);
        area += dfs(grid, i - 1, j, n, m);
        area += dfs(grid, i, j + 1, n, m);
        area += dfs(grid, i, j - 1, n, m);

        return area;
    }
};
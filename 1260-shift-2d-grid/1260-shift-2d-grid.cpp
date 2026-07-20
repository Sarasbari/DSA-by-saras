class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;
        k %= total;
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int index = i * n + j;
                int newindex = (index + k) % total;
                int newRow = newindex / n;
                int newcol = newindex % n;
                ans[newRow][newcol] = grid[i][j];
            }
        }
        return ans;
    }
};
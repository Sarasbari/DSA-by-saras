class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (dp[r][c] != 0)
            return dp[r][c];
        dp[r][c] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (matrix[nr][nc] > matrix[r][c]) {
                dp[r][c] = max(dp[r][c], 1 + dfs(matrix, nr, nc));
            }
        }
        return dp[r][c];
    }
};
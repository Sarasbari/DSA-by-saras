class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if (time != dist[r][c])
                continue;
            if (r == n - 1 && c == n - 1)
                return time;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                int newtime = max(time, grid[nr][nc]);
                if (newtime < dist[nr][nc]) {
                    dist[nr][nc] = newtime;
                    pq.push({newtime, nr, nc});
                }
            }
        }
        return -1;
    }
};
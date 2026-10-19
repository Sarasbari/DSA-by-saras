class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> mindist(n, INT_MAX);
        vector<bool> visited(n, false);

        mindist[0] = 0;
        int totalcost = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;

            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || mindist[j] < mindist[u]))
                    u = j;
            }
            visited[u] = true;
            totalcost += mindist[u];

            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int distance = abs(points[u][0] - points[v][0]) +
                                   abs(points[u][1] - points[v][1]);
                    mindist[v] = min(mindist[v], distance);
                }
            }
        }
        return totalcost;
    }
};
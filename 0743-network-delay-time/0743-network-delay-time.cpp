class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        // Build graph: {destination, travel time}
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // Min heap: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            // Ignore outdated heap entries
            if (time > dist[node]) {
                continue;
            }

            for (auto [neighbor, weight] : adj[node]) {
                int newTime = time + weight;

                if (newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                }
            }
        }

        int answer = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};

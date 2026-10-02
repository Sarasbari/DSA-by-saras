class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {

        // Sort intervals by starting point
        sort(intervals.begin(), intervals.end());

        // Store queries with their original index
        vector<pair<int, int>> qs;

        for (int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }

        // Sort queries by value
        sort(qs.begin(), qs.end());

        // Min Heap: {interval size, right endpoint}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> ans(queries.size(), -1);

        int i = 0;

        for (auto [q, index] : qs) {

            // Add every interval that has started by q
            while (i < intervals.size() && intervals[i][0] <= q) {

                int left = intervals[i][0];
                int right = intervals[i][1];

                int size = right - left + 1;

                pq.push({size, right});

                i++;
            }

            // Remove intervals that ended before q
            while (!pq.empty() && pq.top().second < q) {

                pq.pop();
            }

            // Smallest valid interval
            if (!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }

        return ans;
    }
};
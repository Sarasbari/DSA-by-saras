class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.push_back({intervals[i][1], intervals[i][0]});
        }
        sort(meetings.begin(), meetings.end());
        int count = 0;
        int lastend = meetings[0].first;

        for (int i = 1; i < n; i++) {
            int start = meetings[i].second;
            int end = meetings[i].first;

            if (start < lastend)
                count++;
            else
                lastend = end;
        }
        return count;
    }
};
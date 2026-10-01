class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int r = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        for (int i = 0; i < r;) {
            int j = i + 1;
            while (j < r && intervals[i][1] >= intervals[j][0]) {
                intervals[i][1] = max(intervals[j][1], intervals[i][1]);
                j++;
            }
            ans.push_back({intervals[i][0], intervals[i][1]});
            i = j;
        }
        return ans;
    }
};
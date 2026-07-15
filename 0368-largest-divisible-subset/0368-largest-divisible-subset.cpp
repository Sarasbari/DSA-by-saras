class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans;
        vector<int> dp(n, 0);
        vector<int> parent(n);
        int lastindex = 0;
        int maxsize = 0;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1) {
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }
            if (dp[i] > maxsize) {
                lastindex = i;
                maxsize = dp[i];
            }
        }
        int i = lastindex;
        while (parent[i] != i) {
            ans.push_back(nums[i]);
            i = parent[i];
        }
        ans.push_back(nums[i]);

        return ans;
    }
};
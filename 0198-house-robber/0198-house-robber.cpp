class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n - 1, dp);
    }

    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i == 0)
            return nums[0];
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int notTake = solve(nums, i - 1, dp);
        int take = nums[i] + solve(nums, i - 2, dp);

        return dp[i] = max(notTake, take);
    }
};
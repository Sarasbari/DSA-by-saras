class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;

        for (int num : nums)
            total += num;

        if (total % 2 == 1)
            return false;

        int target = total / 2;

        vector<int> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                if (!dp[i - num])
                    continue;
                dp[i] = true;
            }
        }
        return dp[target];
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;

        for (int i = 0; i < n; i++)
            totalsum += nums[i];

        if (totalsum % 2 == 1)
            return false;
        else {
            int k = totalsum / 2;

            vector<bool> prev(k + 1, false);
            prev[0] = true;

            if (nums[0] <= k)
                prev[nums[0]] = true;
            for (int i = 1; i < n; i++) {
                vector<bool> curr(k + 1, false);
                curr[0] = true;
                for (int target = 1; target <= k; target++) {
                    bool notaken = prev[target];
                    bool taken = false;
                    if (nums[i] <= target)
                        taken = prev[target - nums[i]];
                    curr[target] = notaken || taken;
                }
                prev = curr;
            }
            return prev[k];
        }
    }
};
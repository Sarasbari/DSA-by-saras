class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int first = solve(nums, 0, n - 2);
        int second = solve(nums, 1, n - 1);

        return max(first, second);
    }

    int solve(vector<int>& nums, int start, int end) {
        int before = 0;
        int after = 0;

        for (int i = start; i <= end; i++) {
            int take = nums[i] + before;
            int notTake = after;

            int curr = max(take, notTake);

            before = after;
            after = curr;
        }
        return after;
    }
};
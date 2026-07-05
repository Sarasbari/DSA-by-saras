class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<vector<int>> left(n + 1), right(n + 1);

        // Generate all subset sums
        for (int mask = 0; mask < (1 << n); mask++) {
            int leftSum = 0, rightSum = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    leftSum += nums[i];
                    rightSum += nums[i + n];
                }
            }

            left[cnt].push_back(leftSum);
            right[cnt].push_back(rightSum);
        }

        // Sort all right subset sums
        for (int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        // Try every left subset
        for (int cntLeft = 0; cntLeft <= n; cntLeft++) {

            int cntRight = n - cntLeft;

            for (int leftSum : left[cntLeft]) {

                int target = total / 2 - leftSum;

                auto &vec = right[cntRight];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int selected = leftSum + *it;
                    ans = min(ans, abs(total - 2 * selected));
                }

                if (it != vec.begin()) {
                    --it;
                    int selected = leftSum + *it;
                    ans = min(ans, abs(total - 2 * selected));
                }
            }
        }

        return ans;
    }
};
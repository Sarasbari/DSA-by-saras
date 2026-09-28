class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        nth_element(nums.begin(), nums.begin() + (n - k), nums.end());

        return nums[n - k];
    }
};
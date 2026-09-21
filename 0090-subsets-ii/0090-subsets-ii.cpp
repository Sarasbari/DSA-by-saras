class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        bt(nums, 0, res, subset);
        return res;
    }

    void bt(vector<int>& nums, int index, vector<vector<int>>& res,
            vector<int>& subset) {
        int n = nums.size();
        res.push_back(subset);

        for (auto i = index; i < n; i++) {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            subset.push_back(nums[i]);
            bt(nums, i + 1, res, subset);
            subset.pop_back();
        }
    }
};
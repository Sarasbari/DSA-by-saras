class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];
            if (mp.count(needed))
                return {mp[needed], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};
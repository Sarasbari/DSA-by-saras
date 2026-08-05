class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for (auto& it : freq) {
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for (int i = n; i >= 1; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(candidates, target, 0, ans, curr);
        return ans;
    }

    void solve(vector<int>& candidates, int target, int start,
               vector<vector<int>>& ans, vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            curr.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, ans, curr);
            curr.pop_back();
        }
    }
};
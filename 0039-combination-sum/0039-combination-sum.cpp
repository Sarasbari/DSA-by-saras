class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        decison_tree(candidates, target, res, curr, 0, 0);
        return res;
    }

    void decison_tree(vector<int>& candidates, int target,
                      vector<vector<int>>& res, vector<int>& curr, int i,
                      int total) {
        if (total == target) {
            res.push_back(curr);
            return;
        }
        if (total > target)
            return;

        for (int s = i; s < candidates.size(); ++s) {
            curr.push_back(candidates[s]);
            decison_tree(candidates, target, res, curr, s,
                         total + candidates[s]);
            curr.pop_back();
        }
    }
};
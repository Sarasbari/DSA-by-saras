class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> dp;

    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.assign(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
            }
        }
        bt(s, 0);
        return res;
    }

    void bt(string& s, int start) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (!dp[start][end])
                continue;

            path.push_back(s.substr(start, end - start + 1));
            bt(s, end + 1);
            path.pop_back();
        }
    }
};
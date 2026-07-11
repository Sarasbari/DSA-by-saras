class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<unsigned long long> dp(m + 1, 0);
        dp[m] = 1;

        for (int i = n - 1; i >= 0; i--) {
            vector<unsigned long long> curr(m + 1, 0);
            curr[m] = 1;
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j])
                    curr[j] = dp[j + 1] + dp[j];
                else
                    curr[j] = dp[j];
            }
            dp = curr;
        }
        return (int)dp[0];
    }
};
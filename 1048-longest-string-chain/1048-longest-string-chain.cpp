class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), compare);
        vector<int> dp(n, 1);

        int maxlen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkpossible(words[i], words[j]) && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }

    bool static compare(string& s, string& t) { return s.size() < t.size(); }

    bool checkpossible(string& s, string& t) {
        if (s.size() != t.size() + 1)
            return false;
        int i = 0, j = 0;
        while (i < s.size()) {
            if (j < t.size() && s[i] == t[j]) {
                i++;
                j++;
            } else
                i++;
        }
        if (i == s.size() && j == t.size())
            return true;
        return false;
    }
};
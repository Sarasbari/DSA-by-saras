class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastseen(128, -1);
        int left = 0;
        int maxlen = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            if (lastseen[c] >= left)
                left = lastseen[c] + 1;
            lastseen[c] = right;
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};
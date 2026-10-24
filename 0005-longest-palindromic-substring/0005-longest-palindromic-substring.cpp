class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxlen = 1;
        int i = 0;

        while (i < n) {
            int left = i, right = i;
            while (right + 1 < n && s[right + 1] == s[i])
                right++;
            i = right + 1;
            while (left > 0 && right + 1 < n && s[left - 1] == s[right+1]) {
                left--;
                right++;
            }
            int len = right - left + 1;
            if (len > maxlen) {
                maxlen = len;
                start = left;
            }
        }
        return s.substr(start, maxlen);
    }
};
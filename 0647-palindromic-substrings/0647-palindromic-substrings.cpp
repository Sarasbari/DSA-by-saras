class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        int left, right;

        for (int i = 0; i < n; i++) {
            left = right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                res++;
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                res++;
                left--;
                right++;
            }
        }
        return res;
    }
};
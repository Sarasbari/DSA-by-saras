class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int write = 0;

        for (int read = 0; read < n; read++) {
            if (s[read] != ' ') {
                if (write != 0) {
                    s[write++] = ' ';
                }
                int start = read;
                while (read < n && s[read] != ' ') {
                    s[write++] = s[read++];
                }
                read--;
            }
        }
        s.resize(write);
        reverse(s.begin(), s.end());

        int start = 0;
        for (int end = 0; end <= s.length(); end++) {
            if (s[end] == ' ' || end == s.length()) {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
    }
};
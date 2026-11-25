class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;

        while (read < chars.size()) {
            char currentchar = chars[read];
            int count = 0;

            while (read < chars.size() && chars[read] == currentchar) {
                read++;
                count++;
            }
            chars[write++] = currentchar;
            if (count > 1) {
                string countstr = to_string(count);
                for (char c : countstr)
                    chars[write++] = c;
            }
        }
        return write;
    }
};
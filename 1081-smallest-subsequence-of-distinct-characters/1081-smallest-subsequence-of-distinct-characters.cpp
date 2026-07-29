class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        vector<bool> visited(26, false);
        string st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (visited[ch - 'a'])
                continue;
            while (!st.empty() && ch < st.back() && last[st.back() - 'a'] > i) {
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(ch);
            visited[ch - 'a'] = true;
        }
        return st;
    }
};
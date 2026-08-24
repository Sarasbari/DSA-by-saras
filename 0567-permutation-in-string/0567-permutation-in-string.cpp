class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);
        for (char c : s1) {
            need[c - 'a']++;
        }
        int k = s1.length();
        for (int i = 0; i < k; i++) {
            window[s2[i] - 'a']++;
        }
        if (need == window)
            return true;
        for (int right = k; right < s2.length(); right++) {
            window[s2[right] - 'a']++;     // add new character
            window[s2[right - k] - 'a']--; // removing character leaving window
            if (need == window)
                return true;
        }
        return false;
    }
};
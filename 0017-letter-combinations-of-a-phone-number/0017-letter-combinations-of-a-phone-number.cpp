class Solution {
public:
    vector<string> res;

    vector<string> mp = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void bt(string& digits, int index, string& curr) {

        // All digits processed
        if (index == digits.size()) {
            res.push_back(curr);
            return;
        }

        // Letters available for current digit
        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {

            // Choose
            curr.push_back(ch);

            // Explore
            bt(digits, index + 1, curr);

            // Undo
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        string curr;
        bt(digits, 0, curr);

        return res;
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n = num1.size();
        int m = num2.size();
        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int prod = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1];
                res[i + j + 1] = prod % 10;
                res[i + j] += prod / 10;
            }
        }

        string result;
        for (int d : res) {
            if (result.empty() && d == 0)
                continue;
            result += char('0' + d);
        }
        return result;
    }
};
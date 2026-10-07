class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false, b = false, c = false;
        for (auto& t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                a = a || t[0] == target[0];
                b = b || t[1] == target[1];
                c = c || t[2] == target[2];
            }
        }
        return a && b && c;
    }
};
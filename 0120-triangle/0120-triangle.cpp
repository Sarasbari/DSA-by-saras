class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> front(n, 0);
        vector<int> curr(n, 0);

        for (int j = 0; j < n; j++)
            front[j] = triangle[n - 1][j];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = front[j] + triangle[i][j];
                int diagonal = front[j + 1] + triangle[i][j];

                curr[j] = min(down, diagonal);
            }
            front = curr;
        }
        return front[0];
    }
};
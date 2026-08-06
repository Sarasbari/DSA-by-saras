class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                char ch = board[i][j];

                // Ignore empty cells
                if (ch == '.')
                    continue;

                // Calculate 3x3 box index
                int box = (i / 3) * 3 + (j / 3);

                // Check if number already exists
                if (rows[i].count(ch) || cols[j].count(ch) ||
                    boxes[box].count(ch)) {
                    return false;
                }

                // Insert into row, column and box
                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[box].insert(ch);
            }
        }

        return true;
    }
};
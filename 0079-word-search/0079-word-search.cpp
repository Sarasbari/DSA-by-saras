class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c,
             int index) {

        // Word completely matched
        if (index == word.size())
            return true;

        // Out of bounds
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return false;

        // Wrong character
        if (board[r][c] != word[index])
            return false;

        // Mark visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 directions
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        // Backtrack
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] == word[0]) {

                    if (dfs(board, word, r, c, 0))
                        return true;
                }
            }
        }

        return false;
    }
};

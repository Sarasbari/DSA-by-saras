class Solution {
public:
    vector<vector<string>> res;
    vector<int> col;
    vector<int> diagonal1;
    vector<int> diagonal2;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        col.resize(n, 0);
        diagonal1.resize(2 * n - 1, 0);
        diagonal2.resize(2 * n - 1, 0);

        solve(board, 0, n);
        return res;
    }

    void solve(vector<string>& board, int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c])
                continue;
            if (diagonal1[row - c + n - 1])
                continue;
            if (diagonal2[row + c])
                continue;

            // choose
            board[row][c] = 'Q';
            col[c] = 1;
            diagonal1[row - c + n - 1] = 1;
            diagonal2[row + c] = 1;

            // explore
            solve(board, row + 1, n);

            // undo
            board[row][c] = '.';
            col[c] = 0;
            diagonal1[row - c + n - 1] = 0;
            diagonal2[row + c] = 0;
        }
    }
};
class Solution {
public:
    struct Node {
        Node* child[26];
        string word;

        Node() {
            word = "";

            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;
    vector<string> ans;

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        root = new Node();
        for (string word : words)
            insert(word);

        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dfs(board, r, c, root);
            }
        }
        return ans;
    }

    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr) {
                curr->child[index] = new Node();
            }
            curr = curr->child[index];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, Node* curr) {
        char ch = board[r][c];
        int index = ch - 'a';

        if (curr->child[index] == nullptr)
            return;
        curr = curr->child[index];
        
        if (curr->word != "") {
            ans.push_back(curr->word);
            curr->word = "";
        }

        board[r][c] = '#';
        int m = board.size();
        int n = board[0].size();

        if (r > 0 && board[r - 1][c] != '#')
            dfs(board, r - 1, c, curr);
        if (r < m - 1 && board[r + 1][c] != '#')
            dfs(board, r + 1, c, curr);
        if (c > 0 && board[r][c - 1] != '#')
            dfs(board, r, c - 1, curr);
        if (c < n - 1 && board[r][c + 1] != '#')
            dfs(board, r, c + 1, curr);

        board[r][c] = ch;
    }
};
class WordDictionary {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;

    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';
            if (curr->child[index] == nullptr)
                curr->child[index] = new Node();
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }

    bool search(string word) { return dfs(root, word, 0); }

    bool dfs(Node* curr, string& word, int index) {
        if (index == word.size())
            return curr->isEnd;
        char ch = word[index];

        if (ch != '.') {
            int i = ch - 'a';
            if (curr->child[i] == nullptr)
                return false;
            return dfs(curr->child[i], word, index + 1);
        }

        for (int i = 0; i < 26; i++) {
            if (curr->child[i] != nullptr) {
                if (dfs(curr->child[i], word, index + 1))
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
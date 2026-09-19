class Trie {
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

    Trie() { root = new Node(); }

    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr) {
                curr->child[index] = new Node();
            }

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr) {
                return false;
            }

            curr = curr->child[index];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        Node* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (curr->child[index] == nullptr) {
                return false;
            }

            curr = curr->child[index];
        }

        return true;
    }
};
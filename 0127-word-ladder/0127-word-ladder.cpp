class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord)
                return steps;
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (dict.find(temp) != dict.end()) {
                        q.push({temp, steps + 1});
                        dict.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> parents;

    void backtrack(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }
        for (string& p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};

        unordered_set<string> currLevel;
        currLevel.insert(beginWord);

        unordered_set<string> visited;  // words visited in this level
        bool found = false;

        while (!currLevel.empty() && !found) {
            unordered_set<string> nextLevel;
            for (string word : currLevel) wordSet.erase(word);  // avoid cycles

            for (string word : currLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char old = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (wordSet.count(temp)) {
                            parents[temp].push_back(word);
                            nextLevel.insert(temp);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = old;
                }
            }
            currLevel = nextLevel;
        }

        if (!found) return {};
        vector<string> path = {endWord};
        backtrack(endWord, beginWord, path);
        return res;
    }
};

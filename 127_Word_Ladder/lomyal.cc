// BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> word_set(wordList.begin(), wordList.end());
        if (word_set.count(endWord) == 0) {
            return 0;
        }
        std::queue<std::string> to_visit;
        to_visit.push(beginWord);
        int step = 1;
        while (to_visit.size() != 0) {
            int size = to_visit.size();
            for (int i = 0; i < size; ++i) {
                std::string cur_word = to_visit.front();
                if (cur_word == endWord) {
                    return step;  // 要求返回最短变换，因此不用遍历所有
                }
                to_visit.pop();
                add_to_visit(cur_word, word_set, to_visit);  // O(25L)
            }
            ++step;  // 深度
        }
        return 0;
    }
private:
    void add_to_visit(const std::string& word,
            std::unordered_set<std::string>& word_set,
            std::queue<std::string>& to_visit) {
        std::string word_mod(word);
        for (int i = 0; i < word_mod.size(); ++i) {  // 每个位置的字母都换下
            char x = word_mod[i];
            for (char y = 'a'; y <= 'z'; ++y) {  // 尝试换成其他字母
                if (x != y) {
                    word_mod[i] = y;
                    if (word_set.count(word_mod) != 0) {
                        to_visit.push(word_mod);
                        word_set.erase(word_mod);
                    }
                }
            }
            word_mod[i] = x;
        }
    }
};

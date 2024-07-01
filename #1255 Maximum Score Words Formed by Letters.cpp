class Solution {
public:
    int maxScore = 0;

    int calculateScore(string &word, unordered_map<char, int>& letterCount, vector<int>& letterScores) {
        int currentScore = 0;
        for (char ch : word) {
            if (letterCount.count(ch)) {
                if (letterCount[ch] > 0) {
                    currentScore += letterScores[ch - 'a'];
                    letterCount[ch]--;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        }
        return currentScore;
    }

    void findMaxScore(int index, vector<string>& words, vector<int>& letterScores, unordered_map<char, int> letterCount, int currentVal) {
        if (index == words.size()) {
            maxScore = max(maxScore, currentVal);
            return;
        }

        findMaxScore(index + 1, words, letterScores, letterCount, currentVal);

        int wordScore = calculateScore(words[index], letterCount, letterScores);
        if (wordScore > 0) {
            findMaxScore(index + 1, words, letterScores, letterCount, currentVal + wordScore);
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& letterScores) {
        unordered_map<char, int> letterCount;
        for (char ch : letters) {
            letterCount[ch]++;
        }
        findMaxScore(0, words, letterScores, letterCount, 0);
        return maxScore;
    }
};
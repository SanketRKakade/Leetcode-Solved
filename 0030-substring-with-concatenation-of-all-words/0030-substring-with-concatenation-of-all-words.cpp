class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = s.size();
        if (m == 0 || words.empty()) return {};
        int n = words.size();
        int k = words[0].size();
        if (k == 0) return {};
        int total_len = n * k;
        if (m < total_len) return {};

        unordered_map<string, int> wordFreq;
        for (const auto& word : words) {
            wordFreq[word]++;
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            int left = i;
            int right = i;
            int found = 0;
            unordered_map<string, int> windowCnt;
            while (right + k <= m) {
                string word = s.substr(right, k);
                right += k;
                if (wordFreq.count(word)) {
                    windowCnt[word]++;
                    if (windowCnt[word] == wordFreq[word]) {
                        found++;
                    }
                }
                while (left + total_len < right) {
                    string leftWord = s.substr(left, k);
                    left += k;
                    if (wordFreq.count(leftWord)) {
                        if (windowCnt[leftWord] == wordFreq[leftWord]) {
                            found--;
                        }
                        windowCnt[leftWord]--;
                        if (windowCnt[leftWord] == 0) {
                            windowCnt.erase(leftWord);
                        }
                    }
                }
                if (found == static_cast<int>(wordFreq.size()) && (right - left) == total_len) {
                    result.push_back(left);
                }
            }
        }
        return result;
    }
};
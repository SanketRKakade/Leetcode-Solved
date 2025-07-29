class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> index;
        vector<vector<int>> res;

        // Map each word to its index
        for (int i = 0; i < words.size(); i++) {
            index[words[i]] = i;
        }

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int len = word.size();

            for (int j = 0; j <= len; j++) {
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                // Case 1: prefix is palindrome
                if (isPalindrome(prefix)) {
                    string reversedSuffix = suffix;
                    reverse(reversedSuffix.begin(), reversedSuffix.end());
                    if (index.count(reversedSuffix) && index[reversedSuffix] != i) {
                        res.push_back({ index[reversedSuffix], i });
                    }
                }

                // Case 2: suffix is palindrome
                if (j != len && isPalindrome(suffix)) {
                    string reversedPrefix = prefix;
                    reverse(reversedPrefix.begin(), reversedPrefix.end());
                    if (index.count(reversedPrefix) && index[reversedPrefix] != i) {
                        res.push_back({ i, index[reversedPrefix] });
                    }
                }
            }
        }

        return res;
    }

    // Helper to check palindrome
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
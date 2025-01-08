class Solution {
public:
    bool isPrefixAndSuffix(string a, string b) {
        if (a.length() > b.length()) return false;
        if (a == b) return true;
        
        bool isPrefix = true;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                isPrefix = false;
                break;
            }
        }
        
        bool isSuffix = true;
        for (int i = 0; i < a.size(); i++) {
            if (a[a.size() - 1 - i] != b[b.size() - 1 - i]) {
                isSuffix = false;
                break;
            }
        }
        
        return isPrefix && isSuffix;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) count++;
            }
        }
        return count;
    }
};

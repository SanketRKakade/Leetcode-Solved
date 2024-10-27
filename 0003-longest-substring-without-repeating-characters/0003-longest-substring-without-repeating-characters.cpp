class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 1) {
            return 1;
        }
        int hash[256];
        fill(begin(hash), end(hash), -1); // Initialize the hash array to -1
        int l = 0, r = 0;
        int maxlen = 0;
        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            maxlen = max(r - l + 1, maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};

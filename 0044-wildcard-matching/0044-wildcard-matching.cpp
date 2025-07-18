class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // dp[i][j] means s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        // Handle patterns like *, **, ***, etc. at the start
        for (int j = 1; j <= n; ++j)
            if (p[j-1] == '*') dp[0][j] = dp[0][j-1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '*') {
                    // '*' matches empty or one more char
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                    // Single char match or '?'
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

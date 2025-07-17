class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 2;
        
        for (int j = 0; j < k; ++j) {
            vector<int> dp(k, 0);  

            for (int num : nums) {
                int mod = num % k;
                int pos = (j - mod + k) % k;  
                dp[mod] = dp[pos] + 1;
            }

            for (int len : dp) {
                res = max(res, len);
            }
        }
        return res;
    }
};
class Solution {
private:
    
    
public:
    int rob(vector<int>& a){
        int n=a.size();
        vector<int>dp(n,-1);

        dp[0] = a[0];

        for(int i=1 ; i<n ; i++){
            int take = a[i];
            if(i>1) take += dp[i-2];
            int not_take = dp[i-1];

            dp[i] = max(take, not_take);
        }
        return dp[n-1];
        
    }
};
class Solution {
public:
    int f(int ind, vector<int>&dp){
        if(ind==0) dp[0]=0;
        if(ind==1) dp[1]=1;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = f(ind-1,dp) + f(ind-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        f(n,dp);
        return dp[n];
    }
};
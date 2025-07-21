class Solution {
private:
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == 0) return nums[ind];
        if(ind < 1) return 0;

        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + f(ind-2, nums, dp);
        int not_pick = 0 + f(ind-1, nums, dp);

        return dp[ind] = max(pick, not_pick);
    }
public:
    int rob(vector<int>& nums){
        int n=nums.size();
        if(n==1) return nums[0];
    
        vector<int>temp1, temp2;
        for(int i=0 ; i<n ; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);

        int ans1 = f(temp1.size()-1 , temp1, dp1);
        int ans2 = f(temp2.size()-1, temp2, dp2);
        return max(ans1, ans2);
    }
};
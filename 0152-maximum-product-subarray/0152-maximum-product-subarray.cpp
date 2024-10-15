class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suff = 1;
        int pref = 1;
        int maxi = INT_MIN;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;
            pref*=nums[i];
            suff*=nums[n-i-1];
            maxi = max(maxi,max(suff,pref));
        }
        return maxi;
    }
};
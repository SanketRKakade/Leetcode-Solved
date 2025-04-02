class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n= nums.size();
        if(n<3) return 0;

        long long max_res = 0;
        int max_val = nums[0];
        int max_diff = 0;

        for(int i=1 ; i<n ; i++){
            max_res = max(max_res , (long long)max_diff * nums[i]);
            max_diff = max(max_diff , max_val - nums[i]);
            max_val = max(max_val , nums[i]);
        }
        return max_res;
    }
};
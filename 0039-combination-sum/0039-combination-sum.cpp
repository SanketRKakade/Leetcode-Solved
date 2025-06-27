class Solution {
public:

    void fun(int i,vector<int>& temp, vector<int>& nums,vector<vector<int>>&ans, int k){
        if(i == nums.size()){
            if(k==0){
                ans.push_back(temp);
            }
            return ;
        }


        if(nums[i] <=k ){
            temp.push_back(nums[i]); 
            fun(i,temp,nums,ans,k-nums[i]);
            temp.pop_back();  
        }

        fun(i+1,temp,nums,ans,k);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(0,temp,candidates,ans,target);
        return ans;
    }
};
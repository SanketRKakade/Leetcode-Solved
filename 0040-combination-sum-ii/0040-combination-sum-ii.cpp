class Solution {
public:

    void fun(int ind, vector<int>&nums, int target, vector<int>&temp, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return ;
        }

        for(int i=ind ; i<nums.size() ; i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;

            temp.push_back(nums[i]);
            fun(i+1,nums,target-nums[i],temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>temp;
        fun(0,candidates,target,temp,ans);
        return ans;
    }
};
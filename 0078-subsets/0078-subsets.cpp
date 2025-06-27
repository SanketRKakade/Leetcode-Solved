class Solution {
public:

    vector<vector<int>> fun(int idx, vector<int>&nums, vector<vector<int>>&ans, vector<int>&temp){
        
        if(idx>=nums.size()){
            ans.push_back(temp);
            return ans;
        } 

        temp.push_back(nums[idx]);
        // ans.push_back(temp);
        fun(idx+1,nums,ans,temp);
        temp.erase(temp.begin()+idx);
        // ans.push_back(temp);
        fun(idx+1,nums,ans,temp);
        return ans;

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        return fun(0,nums,ans,temp);
    }
};
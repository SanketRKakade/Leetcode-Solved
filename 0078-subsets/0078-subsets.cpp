class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int subsets = 1<<nums.size() ;//(2^n)

        for(int i = 0 ; i<subsets ; i++){
            vector<int>temp;
            for(int j=0 ; j<nums.size() ; j++){
                if(i & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
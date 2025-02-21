class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        nums.clear();
        for(auto i:mp){
            if(i.second>n/3) nums.push_back(i.first);
        }
        // sort(nums.begin(),nums.end());
        return nums;
    }
};
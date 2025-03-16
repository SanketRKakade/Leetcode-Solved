class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        nums.clear();
        for(auto i:mp){
            for(int j=0 ; j<i.second ; j++){
                nums.push_back(i.first);
            }
        }

    }
};
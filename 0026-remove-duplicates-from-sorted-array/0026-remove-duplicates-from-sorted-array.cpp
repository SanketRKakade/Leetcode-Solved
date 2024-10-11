class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int max = nums[nums.size()-1];
        // int range = max-nums[0]+1;
        // int j=0;
        // for(int i=nums[0] ; i<nums[0]+range ; i++){
        //     nums[j]=i;
        //     j++;
        // }
        // return range;
        int n = nums.size();
        int i=0 ; 
        set<int>mySet(nums.begin(),nums.end());
        for (auto it = mySet.begin(); it != mySet.end(); ++it) {
            nums[i]=*it;
            i++;
        }
        return mySet.size();
    }
};
class Solution {
public:
    int solve(int first,int last,vector<int>nums,int target){
        if(first>last) return -1;
        int mid = (last+first)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return solve(mid+1,last,nums,target);
        else return solve(first,mid-1,nums,target);
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return solve(0,nums.size()-1,nums,target);
    }
};
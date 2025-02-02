class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>temp = nums;
        sort(temp.begin(),temp.end());
        if(nums==temp) return true;
        auto itr = min_element(nums.begin(),nums.end());
        int miniIndex = distance(nums.begin(),itr);
        // cout<<miniIndex<<endl;
        int i = nums.size()-miniIndex;
        while(i > 0){
            if(nums==temp) return true;
            int tempo = nums[nums.size()-1];
            nums.pop_back();
            nums.insert(nums.begin(),tempo);
            i--;
        }
        if(temp==nums) return true;
        return false;
    }
};



















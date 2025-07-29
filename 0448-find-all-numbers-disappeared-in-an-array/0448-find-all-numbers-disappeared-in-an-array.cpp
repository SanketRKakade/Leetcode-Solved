class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        set<int> sett;
        for (int i=0 ; i<n ; i++){
            sett.insert(nums[i]);
        }
        for(int i= 1 ; i<=n ; i++){
            if (!sett.count(i)){
                ans.push_back(i);
            }
        }

        return ans;


    }
};
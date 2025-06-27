class Solution {
public:
    vector<vector<int>> fun(int i, int &sum, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans, int k) {
        if (i >= nums.size()) {
            if (sum == k) {
                ans.push_back(temp);
            }
            return ans;  
        }

        // include current element if sum does not exceed target
        if (sum + nums[i] <= k) {
            temp.push_back(nums[i]);
            sum += nums[i];

            fun(i, sum, temp, nums, ans, k);  // include same element again (i)

            sum -= nums[i];  // backtrack
            temp.pop_back();
        }

        // exclude current element
        fun(i + 1, sum, temp, nums, ans, k);

        return ans;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        return fun(0, sum, temp, candidates, ans, target);
    }
};

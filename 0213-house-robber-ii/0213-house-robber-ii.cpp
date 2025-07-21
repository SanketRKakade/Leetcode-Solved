class Solution {
private:
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = 0;
        int prev = nums[0];

        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int not_pick = prev;
            int curr = max(pick, not_pick);

            // update for next step
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> temp1(nums.begin() + 1, nums.end());     // Exclude first house
        vector<int> temp2(nums.begin(), nums.end() - 1);     // Exclude last house

        int ans1 = robLinear(temp1);
        int ans2 = robLinear(temp2);

        return max(ans1, ans2);
    }
};

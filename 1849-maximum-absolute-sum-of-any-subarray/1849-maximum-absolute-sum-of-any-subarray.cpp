class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int curMax = 0, curMin = 0;
        
        for (int num : nums) {
            curMax = max(num, curMax + num);
            curMin = min(num, curMin + num);
            maxSum = max(maxSum, curMax);
            minSum = min(minSum, curMin);
        }
        return max(maxSum, abs(minSum));
    }
};

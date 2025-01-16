class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;

        // Compute XOR of all elements in nums1 and nums2
        for (int num : nums1) {
            xor1 ^= num;
        }
        for (int num : nums2) {
            xor2 ^= num;
        }

        // Determine contributions based on array sizes
        int result = 0;
        if (nums2.size() % 2 != 0) {
            result ^= xor1; // Elements of nums1 appear odd times
        }
        if (nums1.size() % 2 != 0) {
            result ^= xor2; // Elements of nums2 appear odd times
        }

        return result;
    }
};

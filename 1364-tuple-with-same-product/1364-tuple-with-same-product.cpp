class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        // Count the frequency of products
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for(auto& entry : mp) {
            int freq = entry.second;
            if(freq >= 2) {
                ans += 8 * (freq * (freq - 1)) / 2;
            }
        }

        return ans;
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        vector<int> result;
        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int starti = q[2];
            int xi = q[3];
            
            nums[index] = value;
            
            int current_mod = 1;
            int count = 0;
            bool found_zero = false;
            
            for (int i = starti; i < nums.size(); ++i) {
                current_mod = (current_mod * (nums[i] % k)) % k;
                if (current_mod == xi) {
                    ++count;
                }
                if (current_mod == 0) {
                    if (xi == 0) {
                        count += (nums.size() - i - 1);
                    }
                    break;
                }
            }
            result.push_back(count);
        }
        return result;
    }
};
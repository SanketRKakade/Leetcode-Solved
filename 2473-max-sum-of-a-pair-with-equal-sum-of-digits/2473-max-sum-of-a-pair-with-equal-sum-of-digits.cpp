class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;  
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        int maxSum = -1;

        for (int num : nums) {
            int digitSum = sumOfDigits(num);
            
            if (!mp.count(digitSum)) {
                mp[digitSum] = {num, -1};
            } else {
                auto &[largest, secondLargest] = mp[digitSum];
                if (num > largest) {
                    secondLargest = largest;
                    largest = num;
                } else if (num > secondLargest) {
                    secondLargest = num;
                }
                if (secondLargest != -1) {
                    maxSum = max(maxSum, largest + secondLargest);
                }
            }
        }

        return maxSum;
    }
};

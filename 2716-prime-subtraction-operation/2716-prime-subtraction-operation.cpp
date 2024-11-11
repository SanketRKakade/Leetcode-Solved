 class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        vector<bool> isPrime(1001, true);
        for (int i = 2; i <= 1000; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * 2; j <= 1000; j += i) isPrime[j] = false;
            }
        }

        int prev = 0;
        for (int i = 0; i < nums.size(); i++) {
            int newValue = nums[i];
            for (int j = primes.size() - 1; j >= 0; j--) {
                if (primes[j] < nums[i] && (nums[i] - primes[j]) > prev) {
                    newValue = nums[i] - primes[j];
                    break;
                }
            }
            if (newValue <= prev) return false;
            prev = newValue;
        }
        return true;
    }
};

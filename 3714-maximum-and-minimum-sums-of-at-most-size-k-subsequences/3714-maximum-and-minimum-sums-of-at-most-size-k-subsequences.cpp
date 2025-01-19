#include <vector>
#include <algorithm>

class Solution {
public:
    int minMaxSums(std::vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        long long totalSum = 0;
        std::sort(nums.begin(), nums.end());

        std::vector<long long> fact(n + 1, 1), invFact(n + 1, 1);

        auto modInverse = [&](long long x, int mod) -> long long {
            long long result = 1, power = mod - 2;
            while (power) {
                if (power % 2) result = (result * x) % mod;
                x = (x * x) % mod;
                power /= 2;
            }
            return result;
        };

        for (int i = 2; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = modInverse(fact[n], MOD);
        for (int i = n - 1; i >= 0; --i) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        auto comb = [&](int n, int r) -> long long {
            if (r > n || r < 0) return 0;
            return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
        };

        for (int i = 0; i < n; ++i) {
            for (int size = 1; size <= k; ++size) {
                long long minContribution = comb(i, size - 1);
                totalSum = (totalSum + nums[i] * minContribution) % MOD;
            }

            for (int size = 1; size <= k; ++size) {
                long long maxContribution = comb(n - i - 1, size - 1);
                totalSum = (totalSum + nums[i] * maxContribution) % MOD;
            }
        }

        return static_cast<int>(totalSum);
    }
};

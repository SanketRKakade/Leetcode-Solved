class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mapp;
        int even = 0;
        for (auto a : s) {
            mapp[a]++;
        }

        bool hasOdd = false;

        for (auto m : mapp) {
            even += (m.second / 2) * 2;
            if (m.second % 2) {
                hasOdd = true;
            }
        }

        return hasOdd ? even + 1 : even;
    }
};
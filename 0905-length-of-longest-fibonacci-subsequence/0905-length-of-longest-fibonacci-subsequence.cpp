class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> set(arr.begin(), arr.end());
        int maxLength = 0;
        
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int a = arr[i], b = arr[j], len = 2;
                while (set.find(a + b) != set.end()) {
                    int temp = a + b;
                    a = b;
                    b = temp;
                    len++;
                    maxLength = max(maxLength, len);
                }
            }
        }
        
        return maxLength;
    }
};
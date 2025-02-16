class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(result, used, 0, n);
        return result;
    }

private:
    bool backtrack(vector<int>& result, vector<bool>& used, int index, int n) {
        if (index == result.size()) return true;
        if (result[index] != 0) return backtrack(result, used, index + 1, n);

        for (int num = n; num >= 1; num--) {
            if (used[num]) continue;
            if (num == 1) {
                result[index] = 1;
                used[1] = true;
                if (backtrack(result, used, index + 1, n)) return true;
                result[index] = 0;
                used[1] = false;
            } else {
                int nextIndex = index + num;
                if (nextIndex < result.size() && result[nextIndex] == 0) {
                    result[index] = result[nextIndex] = num;
                    used[num] = true;
                    if (backtrack(result, used, index + 1, n)) return true;
                    result[index] = result[nextIndex] = 0;
                    used[num] = false;
                }
            }
        }
        return false;
    }
};

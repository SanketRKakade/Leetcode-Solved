class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, left = 0, right = n - 1, bottom = n - 1;
        int count = 1;
        vector<vector<int>> arr(n, vector<int>(n, 0));

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) arr[top][i] = count++;
            top++;

            for (int i = top; i <= bottom; i++) arr[i][right] = count++;
            right--;

            if (top <= bottom)
                for (int i = right; i >= left; i--) arr[bottom][i] = count++;
            bottom--;

            if (left <= right)
                for (int i = bottom; i >= top; i--) arr[i][left] = count++;
            left++;
        }

        return arr;
    }
};
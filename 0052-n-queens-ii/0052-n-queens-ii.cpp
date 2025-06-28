class Solution {
public:
    

void countSolutions(int col, int n, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int& count) {
    if (col == n) {
        count++;
        return;
    }

    for (int row = 0; row < n; row++) {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {

            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;

            countSolutions(col + 1, n, leftRow, lowerDiagonal, upperDiagonal, count);

            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

    int totalNQueens(int n) {
        vector<int> leftRow(n, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        int count = 0;

        countSolutions(0, n, leftRow, lowerDiagonal, upperDiagonal, count);
        return count;
    }


};
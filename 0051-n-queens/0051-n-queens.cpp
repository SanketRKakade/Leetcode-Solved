class Solution {
public:

    // Function to check if placing a queen at (row, col) is safe
    bool isSafe1(int row, int col, const vector<string>& board, int n) {
        int duprow = row;
        int dupcol = col;

        // Check upper-left diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // Reset row and col
        row = duprow;
        col = dupcol;

        // Check left side of the row
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        // Reset again
        row = duprow;
        col = dupcol;

        // Check lower-left diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0 ; row<n ; row++){
            if(isSafe1(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1, board, ans, n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0 ; i<n ; i++) board[i]=s;

        solve(0,board,ans,n);
        return ans;
    }
};
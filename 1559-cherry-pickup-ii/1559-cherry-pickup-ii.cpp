class Solution {
private:
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        // base condn
        if(j1 < 0 || j1>=c || j2<0 || j2>=c){
            return -1e8;
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        // if last row reached
        if(i == r-1){
            // if both reached at the same point
            if(j1==j2) return grid[i][j1];
            else {
                // they are not at the same spot
                return grid[i][j1] + grid[i][j2];
            }
        }

        int maxi = -1e8;
        //explore all the paths for alice and bob simultanesouly
        for(int dj1 = -1 ; dj1 <=1 ; dj1++){
            for(int dj2 = -1 ; dj2<=1 ; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f(i+1, j1+dj1, j2+dj2, r, c, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2]=maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // dp[m][n][n]
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return f(0,0,n-1,m,n,grid,dp);
    }
};
class Solution {
public:

    void bfs(int n, int m, int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0 ; i<4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;

        for(int row=0 ; row<n ; row++){
            for(int col=0; col<m ; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    bfs(n,m,row,col,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
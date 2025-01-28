class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi = 0;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j]>0){
                    int fish = 0;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        if(grid[x][y]>0){
                            fish += grid[x][y];
                            grid[x][y]=0;
                            if(x>0 && grid[x-1][y]>0) q.push({x-1,y});
                            if(x+1<grid.size() && grid[x+1][y]>0) q.push({x+1,y});
                            if(y>0 && grid[x][y-1]>0) q.push({x,y-1});
                            if(y+1<grid[0].size() && grid[x][y+1]>0) q.push({x,y+1});
                        }
                    }
                    maxi = max(maxi,fish);
                }
            }
        }
        return maxi;
    }
};
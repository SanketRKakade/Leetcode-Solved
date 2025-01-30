class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int searchIn = -1;
        for(int i=0 ; i<m ; i++){
            if(target==matrix[i][0]) return true;
            if(target==matrix[i][n-1]) return true;
            if(target>matrix[i][0] && target<matrix[i][n-1]){
                searchIn = i;
            }
        }
        if(searchIn == -1) return false;
        for(int i=0 ; i<n ; i++){
            if(matrix[searchIn][i]==target) return true;
        }
        return false;
    }
};
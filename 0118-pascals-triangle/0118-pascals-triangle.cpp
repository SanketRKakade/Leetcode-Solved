class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        if(numRows == 0)  return output;
        for(int i=0; i<numRows; i++)
            output.push_back(vector<int>(i + 1, 1));   
        for (int i = 2; i < numRows; ++i)
            for (int j = 1; j < output[i].size() - 1; ++j)
                output[i][j] = output[i - 1][j - 1] + output[i - 1][j];
        return output;      
    }
};
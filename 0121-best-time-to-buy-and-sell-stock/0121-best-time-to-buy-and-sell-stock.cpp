class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = prices[0];
        for(int i=0;i<prices.size() ; i++){
            int diff ;
            mini = min(mini,prices[i]);
            diff = prices[i]-mini;
            maxi = max(maxi,diff);
        }
        return maxi;
    }
};
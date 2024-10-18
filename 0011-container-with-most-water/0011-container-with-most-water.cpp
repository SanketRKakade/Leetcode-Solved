class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0;
        int r=n-1;
        int maxi = INT_MIN;
        while(l<r){
            int currAns = min(height[l], height[r])*(r-l);
            maxi = max(maxi,currAns);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxi;
    }
};
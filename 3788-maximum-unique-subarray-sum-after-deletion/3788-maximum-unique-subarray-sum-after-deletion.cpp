class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        int maxi=INT_MIN;
        for(auto& i:nums){
            if(i<0) maxi = max(maxi,i);
            else st.insert(i);
        }
        if(st.size()==0) return maxi;
        int sum=0;
        for(int i:st) sum+=i;
        return sum;
    }
};
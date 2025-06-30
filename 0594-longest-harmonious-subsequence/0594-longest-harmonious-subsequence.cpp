class Solution {
public:
    int findLHS(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        unordered_map<int,int>mp;

        for(auto &i : arr){
            mp[i]++;
        }

        int count = 0;
        for(int i = 1 ; i < n ; ++i){
            if(abs(arr[i]-arr[i-1]) == 1){
                int hrm = mp[arr[i]] + mp[arr[i-1]];
                count = max(count,hrm);
            }
        }
        return count;
    }
};
class Solution {
public:
    int partitionArray(vector<int>& arr, int diff) {
        sort(arr.begin(), arr.end()); 
        int maxi = arr[0];
        int mini = arr[0];
        int n = arr.size();
        int ans = 1; 

        for (int i = 1; i < n; ++i) {
            mini = min(arr[i], mini);
            maxi = max(arr[i], maxi);

            if (maxi - mini > diff) {
                ans++;
                mini = maxi = arr[i]; 
            } 
        }
        return ans;
    }
};
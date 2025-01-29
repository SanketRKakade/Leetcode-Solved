class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>anss;
        anss.push_back(0);
        for(int i=1 ; i<=n ; i++){
            int ans=0;
            int j=i;
            while(j!=0){
                ans++;
                j &= j-1;
            }
            anss.push_back(ans);
        }
        return anss;
    }
};
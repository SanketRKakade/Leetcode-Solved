class Solution {
private:
    
    
public:
    int rob(vector<int>& a){
        int n=a.size();
        int prev2 = 0;
        int prev = a[0];

        for(int i=1 ; i<n ; i++){
            int take = a[i];
            if(i>1) take += prev2;
            int not_take = prev;

            int curr = max(take, not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
        
    }
};
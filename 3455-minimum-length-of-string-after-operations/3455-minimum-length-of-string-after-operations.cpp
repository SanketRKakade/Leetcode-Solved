class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>m;
        int count=0;
        for(auto i:s){
            m[i]++;
        }
        for(auto i:m){
            if(i.second>2){
                if(i.second %2 == 0){
                    count+=(i.second-2);
                } 
                else count+=(i.second-1);
                // count+=i.second-2;
            }
        }
        return s.length()-count;
    }
};
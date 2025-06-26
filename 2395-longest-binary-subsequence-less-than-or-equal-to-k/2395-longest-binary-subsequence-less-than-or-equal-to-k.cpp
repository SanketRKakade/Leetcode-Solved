class Solution {
public:
    unsigned long long binaryToDecimal(const string& binary) {
        unsigned long long decimal = 0;
        for (char bit : binary) {
            decimal = decimal * 2 + (bit - '0');
            if (decimal > ULLONG_MAX / 2) break; // optional guard
        }
        return decimal;
    }
    int longestSubsequence(string s, int k) {
        string temp = s;
        if(temp.length()==0) return 0;
        if(binaryToDecimal(temp)<=k) return temp.length();
        size_t pos = temp.find('1');  
        if (pos != string::npos) {
            temp.erase(pos, 1);  
            return longestSubsequence(temp,k);     
        }
        return 0;
    }


    // int longestSubsequence(string s, int k) {
    //     if(binaryToDecimal(s)<=k) return s.length();
    //     // sort(s.begin(),s.end());
    //     // cout<<s<<endl;
    //     // return s.length();
    //     for(int i=0 ; i<s.length() ; i++){
    //         if(s[i]==0) continue;
    //         string sub = s.erase(i,1);
    //         if(binaryToDecimal(sub)<=k){
    //             cout<<sub<<endl;
    //             return sub.length();
    //         }
    //     }
    //     return 0;
    // }
};
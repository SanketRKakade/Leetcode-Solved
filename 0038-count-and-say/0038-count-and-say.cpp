class Solution {
public:
        string helper(int n,string ans){
        if(n==0){
            return ans;
        }
        int i=0,j=0;
        string newans="";
        while(i<ans.length()){
         while(ans[i]==ans[j] && i<ans.length()){
             i++;
         }
         newans+=i-j+'0';
         newans+=ans[j];
         j=i;
        }
        return helper(n-1,newans);
    }
public:
    string countAndSay(int n) {
        string ans="1";
       return helper(n-1,ans);
    }
};
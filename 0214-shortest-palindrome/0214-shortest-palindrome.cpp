class Solution 
{
    vector<int> get_lps(string s)
    {
        int size = s.size();
        int j = 0;
        vector<int> lps(size, 0);

        for(int i = 1; i < size; i++){
            while(j > 0 && s[i] != s[j]) {
                j = lps[j-1];
            }

            if(s[i] == s[j]){
                j++;
                lps[i] = j;
            }
            else{
                lps[i] = 0;
            }
        }

        return lps;
    }


public:
    string shortestPalindrome(string s) 
    {
        int size = s.size();
        string revs = s;
        reverse(revs.begin() , revs.end());
        string str = s + '$'+ revs ;
        vector<int> lps = get_lps(str);
        int num = size - lps.back();
        return revs.substr(0,num) + s;
    }
};